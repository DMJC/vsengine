/// Various universe and star system helper functions
///

#include <stdio.h>
#include <fcntl.h>
#include <algorithm>
#include "universe_generic.h"
#include "galaxy_xml.h"
#include "galaxy_gen.h"
#include "gfx/cockpit_generic.h"
#include "cmd/unit_generic.h"
#include "vs_globals.h"
#include "xml_support.h"
#include "cmd/script/mission.h"
#include "vsfilesystem.h"
#include "save_util.h"
#include "cmd/unit_util.h"
#include "universe_util.h"
#include "cmd/csv.h"
#include "cmd/role_bitmask.h"
#include "options.h"
#include <boost/graph/graph_concepts.hpp>

using namespace GalaxyXML;



extern StarSystem * GetLoadedStarSystem( const char *file );
vector< StarSystem* >deleteQueue;
void Universe::clearAllSystems()
{
    while ( star_system.size() ) {
        star_system.back()->RemoveStarsystemFromUniverse();
        delete star_system.back();
        star_system.pop_back();
    }
    active_star_system.clear();
    script_system = NULL;
}

Cockpit* Universe::createCockpit( std::string player )
{
    Cockpit *cp = new Cockpit( "", NULL, player );
    cockpit.push_back( cp );
    return cp;
}

Unit * DockToSavedBases( int playernum, QVector &safevec )
{
    string str = game_options.startDockedTo;
    Unit  *plr = _Universe->AccessCockpit( playernum )->GetParent();
    if ( !plr || !plr->getStarSystem() ) {
        safevec = QVector( 0, 0, 0 );
        return NULL;
    }
    vector< string >strs = loadStringList( playernum, mission_key );
    if ( strs.size() )
        str = strs[0];
    Unit   *closestUnit  = NULL;
    float   lastdist     = 0;
    float   dist = 0;
    Unit   *un;
    QVector dock_position( plr->curr_physical_state.position );
    for (un_iter iter = plr->getStarSystem()->getUnitList().createIterator(); (un = *iter); ++iter)
        if (un->name == str || un->getFullname() == str) {
            dist = UnitUtil::getSignificantDistance( plr, un );
            if (closestUnit == NULL || dist < lastdist) {
                lastdist    = dist;
                closestUnit = un;
            }
        }
    if (closestUnit) {
        if (UnitUtil::getSignificantDistance( plr, closestUnit ) > 0 && closestUnit->isUnit() != PLANETPTR)
            dock_position = closestUnit->Position();
        dock_position = UniverseUtil::SafeEntrancePoint( dock_position, plr->rSize() );
        plr->SetPosAndCumPos( dock_position );

        vector< DockingPorts >dprt = closestUnit->pImage->dockingports;
        unsigned int i;
        for (i = 0;; i++) {
            if ( i >= dprt.size() ) {
                safevec = QVector( 0, 0, 0 );
                return NULL;
            }
            if (!dprt[i].IsOccupied())
                break;
        }
        plr->ForceDock( closestUnit, i );
        closestUnit->pImage->clearedunits.push_back( plr );
        closestUnit->RequestPhysics();
        _Universe->AccessCockpit( playernum )->retry_dock = 0;
    } else {
        if (_Universe->AccessCockpit( playernum )->retry_dock == 0)
            _Universe->AccessCockpit( playernum )->retry_dock = 128;
        else _Universe->AccessCockpit( playernum )->retry_dock -= 1;
    }
    safevec = dock_position;
    return ( closestUnit && closestUnit->isDocked( plr ) ) ? closestUnit : NULL;
}


Cockpit* Universe::isPlayerStarship( const Unit *doNotDereference )
{
    using std::vector;
    if (!doNotDereference)
        return NULL;
    for (std::vector< Cockpit* >::iterator iter = cockpit.begin(); iter < cockpit.end(); iter++)
        if ( doNotDereference == ( *(iter) )->GetParent() )
            return *(iter);
    return NULL;
}

int Universe::whichPlayerStarship( const Unit *doNotDereference )
{
    if (!doNotDereference)
        return -1;
    for (unsigned int i = 0; i < cockpit.size(); i++)
        if ( doNotDereference == cockpit[i]->GetParent() )
            return i;
    return -1;
}

void Universe::SetActiveCockpit( int i )
{
#ifdef VS_DEBUG
    if ( i < 0 || i >= cockpit.size() )
        VSFileSystem::vs_fprintf( stderr, "ouch invalid cockpit %d", i );
#endif
    current_cockpit = i;
}

void Universe::SetActiveCockpit( Cockpit *cp )
{
    for (unsigned int i = 0; i < cockpit.size(); i++)
        if (cockpit[i] == cp) {
            SetActiveCockpit( i );
            return;
        }
}

void Universe::SetupCockpits( vector< string >playerNames )
{
    for (unsigned int i = 0; i < playerNames.size(); i++)
        cockpit.push_back( new Cockpit( "", NULL, playerNames[i] ) );
}

void SortStarSystems( std::vector< StarSystem* > &ss, StarSystem *drawn )
{
    if ( ( *ss.begin() ) == drawn )
        return;
    vector< StarSystem* >::iterator drw = std::find( ss.begin(), ss.end(), drawn );
    if ( drw != ss.end() ) {
        StarSystem *tmp = drawn;
        vector< StarSystem* >::iterator i = ss.begin();
        while (i <= drw) {
            StarSystem *t = *i;
            *i  = tmp;
            tmp = t;
            i++;
        }
    }
}

void Universe::Init( const char *gal )
{
    ROLES::getAllRolePriorities();
    LoadWeapons( VSFileSystem::weapon_list.c_str() );
    galaxy.reset(new GalaxyXML::Galaxy( gal ));
    static bool firsttime = false;
    if (!firsttime) {
        LoadFactionXML( "factions.xml" );
        firsttime = true;
    }
    script_system = NULL;
}

Universe::Universe( int argc, char **argv, const char *galaxy_str, bool server )
    : current_cockpit( 0 )
    , script_system( NULL )
{
    this->Init( galaxy_str );
    network_lock = false;
    is_server    = server;
}

Universe::Universe()
    : current_cockpit( 0 )
    , script_system( NULL )
{
    is_server = false;
}

Universe::~Universe()
{
    factions.clear();
    cockpit.clear();
}

void Universe::LoadStarSystem( StarSystem *s )
{
    std::cerr<<"Loading a starsystem"<<std::endl;
    star_system.push_back( s );
    SortStarSystems( star_system, s );     //dont' want instadie
}

bool Universe::StillExists( StarSystem *s )
{
    return std::find( star_system.begin(), star_system.end(), s ) != star_system.end();
}

bool Universe::netLocked()
{
    return (Network || SERVER) && network_lock;
}

void Universe::netLock( bool enable )
{
    network_lock = false;
    if (Network || SERVER)
        network_lock = enable;
}

void Universe::UnloadStarSystem( StarSystem *s )
{
    //not sure what to do here? serialize?
}

StarSystem* Universe::Init( string systemfile, const Vector &centr, const string planetname )
{
    string fullname = systemfile+".system";
    return GenerateStarSystem( (char*) fullname.c_str(), "", centr );
}

StarSystem* Universe::getStarSystem( string name )
{
    vector< StarSystem* >::iterator iter;
    for (iter = star_system.begin(); iter != star_system.end(); iter++) {
        StarSystem *ss = *iter;
        if (ss->getName() == name)
            return ss;
    }
    return NULL;
}

extern void MakeStarSystem( string file, Galaxy *galaxy, string origin, int forcerandom );
extern string RemoveDotSystem( const char *input );
using namespace VSFileSystem;

static void ss_generating( bool enable )
{
    static bool ss_generating_active = false;
    if (enable) {
        if ( !UniverseUtil::isSplashScreenShowing() ) {
            static const std::string empty;
            UniverseUtil::showSplashScreen( empty );
            ss_generating_active = true;
        }
    } else if (ss_generating_active) {
        UniverseUtil::hideSplashScreen();
        ss_generating_active = false;
    }
}

void Universe::Generate1( const char *file, const char *jumpback )
{
    int count = 0;
    if (game_options.while_loading_starsystem)
        ss_generating( true );
    VSFile  f;
    VSError err = f.OpenReadOnly( file, SystemFile );
    //If the file is not found we generate a system
    if (err > Ok)
        MakeStarSystem( file, galaxy.get(), RemoveDotSystem( jumpback ), count );
    if (SERVER) {
        string filestr( file );
        UniverseUtil::ComputeSystemSerials( filestr );
    }
}

void Universe::Generate2( StarSystem *ss )
{
    static bool firsttime = true;
    LoadStarSystem( ss );
    pushActiveStarSystem( ss );
    for (unsigned int tume = 0; tume <= game_options.num_times_to_simulate_new_star_system*SIM_QUEUE_SIZE+1; ++tume)
        ss->UpdateUnitPhysics( true );
    //notify the director that a new system is loaded (gotta have at least one active star system)
    StarSystem *old_script_system = script_system;
    script_system = ss;
    VSFileSystem::vs_fprintf( stderr, "Loading Star System %s\n", ss->getFileName().c_str() );
    const vector< std::string > &adjacent = getAdjacentStarSystems( ss->getFileName() );
    for (unsigned int i = 0; i < adjacent.size(); i++) {
        VSFileSystem::vs_fprintf( stderr, " Next To: %s\n", adjacent[i].c_str() );
    }
    static bool first = true;
    if (!first)
        mission->DirectorStartStarSystem( ss );
    first = false;
    script_system = old_script_system;
    popActiveStarSystem();
    if ( active_star_system.empty() ) {
        pushActiveStarSystem( ss );
    } else {
        ss->SwapOut();
        activeStarSystem()->SwapIn();
    }
    if (firsttime) {
        firsttime = false;
    } else {}
    ss_generating( false );
}

StarSystem* Universe::GenerateStarSystem( const char *file, const char *jumpback, Vector center )
{
    StarSystem *tmpcache;
    if ( ( tmpcache = GetLoadedStarSystem( file ) ) )
        return tmpcache;
    this->Generate1( file, jumpback );
    StarSystem *ss = new StarSystem( file, center );
    this->Generate2( ss );
    return ss;
}

void Universe::Update()
{
    for (unsigned int i = 0; i < star_system.size(); ++i)
        //Calls the update function for server
        star_system[i]->Update( (i == 0) ? 1 : game_options.InactiveSystemTime/i );
}

int Universe::StarSystemIndex( StarSystem *ss )
{
    for (unsigned int i = 0; i < star_system.size(); i++)
        if (star_system[i] == ss)
            return i;
    return -1;
}

static void AppendUnitTables(const string &csvfiles)
{
    CSVTable *table = loadCSVTableList(csvfiles, VSFileSystem::UnitFile, true);
    if (table != NULL)
        unitTables.push_back(table);
}

void InitUnitTables()
{
    AppendUnitTables(game_options.modUnitCSV);
    AppendUnitTables(game_options.unitCSV);
}

void CleanupUnitTables()
{
    for (std::vector<CSVTable*>::iterator it = unitTables.begin(); it != unitTables.end(); ++it)
    {
        delete *it;
    }
    unitTables.clear();
}
