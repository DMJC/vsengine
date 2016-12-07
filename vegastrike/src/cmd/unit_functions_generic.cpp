#include "unit_generic.h"
#include "gfx/vec.h"
#include "gfx/cockpit_generic.h"
#include "faction_generic.h"
#include "ai/communication.h"
#include "savegame.h"
#include "xml_support.h"
#include "unit_factory.h"
#include "unit_util.h"
#include "universe_util.h"
#include "unit_const_cache.h"
#include "pilot.h"
//Various functions that were used in .cpp files that are now included because of
//the temple GameUnit class
//If not separated from those files functions would be defined in multiple places
//Those functions are generic ones

//From unit.cpp
double saved_interpolation_blend_factor;
double interpolation_blend_factor;
bool   cam_setup_phase = false;

int cloakVal( int cloak, int cloakmin, int cloakrate, bool cloakglass )
{
    //Short fix ?
    if (cloak < 0 && cloakrate < 0)
        cloak = -2147483647-1;          //intended warning should be max neg :-) leave it be
    if (cloak < cloakmin && cloakrate > 0)
        cloak = cloakmin;
    if ( (cloak&0x1) && !cloakglass )
        cloak -= 1;
    if ( (cloak&0x1) == 0 && cloakglass )
        cloak += 1;
    return cloak;
}

const Unit * getUnitFromUpgradeName( const string &upgradeName, int myUnitFaction = 0 )
{
    const char *name     = upgradeName.c_str();
    const Unit *partUnit = UnitConstCache::getCachedConst( StringIntKey( name, FactionUtil::GetUpgradeFaction() ) );
    if (!partUnit) {
        partUnit = UnitConstCache::setCachedConst( StringIntKey( name,
                                                                FactionUtil::GetUpgradeFaction() ),
                                                  UnitFactory::createUnit( name, true, FactionUtil::GetUpgradeFaction() ) );
    }
    if (partUnit->name == "LOAD_FAILED") {
        partUnit = UnitConstCache::getCachedConst( StringIntKey( name, myUnitFaction ) );
        if (!partUnit)
            partUnit = UnitConstCache::setCachedConst( StringIntKey( name, myUnitFaction ),
                                                      UnitFactory::createUnit( name, true, myUnitFaction ) );
    }
    return partUnit;
}

int SelectDockPort( Unit *utdw, Unit *parent )
{
    const vector< DockingPorts > *dp = &utdw->DockingPortLocations();
    float dist = FLT_MAX;
    int   num  = -1;
    for (unsigned int i = 0; i < dp->size(); ++i)
        if (!(*dp)[i].IsOccupied()) {
            Vector rez   = Transform( utdw->GetTransformation(), (*dp)[i].GetPosition() );
            float  wdist = ( rez-parent->Position() ).MagnitudeSquared();
            if (wdist < dist) {
                num  = i;
                dist = wdist;
            }
        }
    return num;
}

//From unit_customize.cpp
Unit * CreateGameTurret( std::string tur, int faction )
{
    return UnitFactory::createUnit( tur.c_str(), true, faction );
}

void SetShieldZero( Unit *un )
{
    switch (un->shield.number)
    {
    case 8:

        un->shield.shield8.frontlefttop =
            un->shield.shield8.frontrighttop   =
                un->shield.shield8.backlefttop =
                    un->shield.shield8.backrighttop =
                        un->shield.shield8.frontleftbottom =
                            un->shield.shield8.frontrightbottom   =
                                un->shield.shield8.backleftbottom =
                                    un->shield.shield8.backrightbottom = 0;
        break;
    case 4:
        un->shield.shield4fbrl.front        =
            un->shield.shield4fbrl.back     =
                un->shield.shield4fbrl.left =
                    un->shield.shield4fbrl.right = 0;
        break;
    case 2:
        un->shield.shield2fb.front = un->shield.shield2fb.back = 0;
        break;
    }
}

//un scored a faction kill
void ScoreKill( Cockpit *cp, Unit *un, Unit *killedUnit )
{
    if (un->isUnit() != UNITPTR || killedUnit->isUnit() != UNITPTR)
        return;
    static float KILL_FACTOR = -XMLSupport::parse_float( vs_config->getVariable( "AI", "kill_factor", ".2" ) );
    int killedCp = _Universe->whichPlayerStarship( killedUnit );
    int killerCp = killedCp;
    if (killedCp != -1) {
        UniverseUtil::adjustRelationModifierInt( killedCp, un->faction, KILL_FACTOR );
    } else {
        killerCp = _Universe->whichPlayerStarship( un );
        if (killerCp != -1)
            UniverseUtil::adjustRelationModifierInt( killerCp, killedUnit->faction, KILL_FACTOR );
    }
    int faction = killedUnit->faction;
    static float FRIEND_FACTOR = -XMLSupport::parse_float( vs_config->getVariable( "AI", "friend_factor", ".1" ) );
    for (unsigned int i = 0; i < FactionUtil::GetNumFactions(); i++) {
        float relation;
        if (faction != (int) i && un->faction != (int) i) {
            relation = FactionUtil::GetIntRelation( i, faction );
            if (killedCp != -1)
                relation += UniverseUtil::getRelationModifierInt( i, faction );
            if (relation)
                if (killerCp != -1)
                    UniverseUtil::adjustRelationModifierInt( killerCp, i, FRIEND_FACTOR*relation );
        }
    }
    int upgrades = FactionUtil::GetUpgradeFaction();
    int planets  = FactionUtil::GetPlanetFaction();
    if (cp != NULL) {
        vector< float > *killlist = &cp->savegame->getMissionData( string( "kills" ) );
        while ( killlist->size() <= FactionUtil::GetNumFactions() )
            killlist->push_back( (float) 0.0 );
        if ( (int) killlist->size() > faction )
            (*killlist)[faction]++;
        killlist->back()++;
    } else if (UnitUtil::getRelationToFaction( un, faction ) < 0 && faction != upgrades && faction != planets) {
        int   whichcp   = rand()%_Universe->numPlayers();
        Unit *whichrecv = _Universe->AccessCockpit( whichcp )->GetParent();
        if (whichrecv != NULL) {
            if ( UnitUtil::getUnitSystemFile( whichrecv ) == UnitUtil::getUnitSystemFile( un ) ) {
                if ( un->getAIState() && whichrecv->getAIState() ) {
                    unsigned char sex;
                    vector< Animation* > *anim = un->pilot->getCommFaces( sex );
                    CommunicationMessage  c( un, whichrecv, anim, sex );
                    c.SetCurrentState( c.fsm->GetScoreKillNode(), anim, sex );
                    whichrecv->getAIState()->Communicate( c );
                }
            }
        }
    }
}

//From unit_physics.cpp
signed char ComputeAutoGuarantee( Unit *un )
{
    Cockpit     *cp;
    unsigned int cpnum = 0;
    if ( ( cp = _Universe->isPlayerStarship( un ) ) )
        cpnum = cp-_Universe->AccessCockpit( 0 );
    else
        return Mission::AUTO_ON;
    unsigned int i;
    for (i = 0; i < active_missions.size(); ++i)
        if (active_missions[i]->player_num == cpnum && active_missions[i]->player_autopilot != Mission::AUTO_NORMAL)
            return active_missions[i]->player_autopilot;
    for (i = 0; i < active_missions.size(); i++)
        if (active_missions[i]->global_autopilot != Mission::AUTO_NORMAL)
            return active_missions[i]->global_autopilot;
    return Mission::AUTO_NORMAL;
}

float getAutoRSize( Unit *orig, Unit *un, bool ignore_friend = false )
{
    static float gamespeed = XMLSupport::parse_float( vs_config->getVariable( "physics", "game_speed", "1" ) );

    static float friendly_autodist =
        XMLSupport::parse_float( vs_config->getVariable( "physics", "friendly_auto_radius", "00" ) )*gamespeed;
    static float neutral_autodist  =
        XMLSupport::parse_float( vs_config->getVariable( "physics", "neutral_auto_radius", "0" ) )*gamespeed;
    static float hostile_autodist  =
        XMLSupport::parse_float( vs_config->getVariable( "physics", "hostile_auto_radius", "1000" ) )*gamespeed;
    int upgradefaction = FactionUtil::GetUpgradeFaction();
    int neutral = FactionUtil::GetNeutralFaction();
    if (un->isUnit() == ASTEROIDPTR) {
        static float minasteroiddistance =
            XMLSupport::parse_float( vs_config->getVariable( "physics", "min_asteroid_distance", "-100" ) );
        return minasteroiddistance;
    }
    if ( un->isUnit() == PLANETPTR || ( un->getFlightgroup() == orig->getFlightgroup() && orig->getFlightgroup() ) )
        //same flihgtgroup
        return orig->rSize();
    if (un->faction == upgradefaction)
        return ignore_friend ? -FLT_MAX : ( -orig->rSize()-un->rSize() );
    float rel = un->getRelation( orig );
    if ( orig == un->Target() )
        rel -= 1.5;
    if (un->faction == neutral)
        return neutral_autodist;
    else if (rel > .1)
        return ignore_friend ? -FLT_MAX : friendly_autodist;          //min distance apart
    else if (rel < 0)
        return hostile_autodist;
    else
        return ignore_friend ? -FLT_MAX : neutral_autodist;
}

//From unit_weapon.cpp
bool AdjustMatrix( Matrix &mat, const Vector &vel, Unit *target, float speed, bool lead, float cone )
{
    if (target) {
        QVector pos( mat.p );
        Vector  R( mat.getR() );
        QVector targpos( lead ? target->PositionITTS( pos, vel, speed, false ) : target->Position() );

        Vector  dir = (targpos-pos).Cast();
        dir.Normalize();
        if (dir.Dot( R ) >= cone) {
            Vector Q( mat.getQ() );
            Vector P;
            ScaledCrossProduct( Q, dir, P );
            ScaledCrossProduct( dir, P, Q );
            VectorAndPositionToMatrix( mat, P, Q, dir, pos );
        } else {
            return false;
        }
        return true;
    }
    return false;
}

enum weapon_info::MOUNT_SIZE lookupMountSize( const char *str )
{
    int  i;
    char tmp[384];
    for (i = 0; i < 383 && str[i] != '\0'; i++)
        tmp[i] = (char) toupper( str[i] );
    tmp[i] = '\0';
    if (strcmp( "LIGHT", tmp ) == 0)
        return weapon_info::LIGHT;
    if (strcmp( "MEDIUM", tmp ) == 0)
        return weapon_info::MEDIUM;
    if (strcmp( "HEAVY", tmp ) == 0)
        return weapon_info::HEAVY;
    if (strcmp( "CAPSHIP-LIGHT", tmp ) == 0)
        return weapon_info::CAPSHIPLIGHT;
    if (strcmp( "CAPSHIP-HEAVY", tmp ) == 0)
        return weapon_info::CAPSHIPHEAVY;
    if (strcmp( "SPECIAL", tmp ) == 0)
        return weapon_info::SPECIAL;
    if (strcmp( "LIGHT-MISSILE", tmp ) == 0)
        return weapon_info::LIGHTMISSILE;
    if (strcmp( "MEDIUM-MISSILE", tmp ) == 0)
        return weapon_info::MEDIUMMISSILE;
    if (strcmp( "HEAVY-MISSILE", tmp ) == 0)
        return weapon_info::HEAVYMISSILE;
    if (strcmp( "LIGHT-CAPSHIP-MISSILE", tmp ) == 0)
        return weapon_info::CAPSHIPLIGHTMISSILE;
    if (strcmp( "HEAVY-CAPSHIP-MISSILE", tmp ) == 0)
        return weapon_info::CAPSHIPHEAVYMISSILE;
    if (strcmp( "SPECIAL-MISSILE", tmp ) == 0)
        return weapon_info::SPECIALMISSILE;
    if (strcmp( "AUTOTRACKING", tmp ) == 0)
        return weapon_info::AUTOTRACKING;
    return weapon_info::NOWEAP;
}

int parseMountSizes( const char *str )
{
    char tmp[13][50];
    int  ans = weapon_info::NOWEAP;
    int  num = sscanf( str,
                       "%s %s %s %s %s %s %s %s %s %s %s %s %s",
                       tmp[0],
                       tmp[1],
                       tmp[2],
                       tmp[3],
                       tmp[4],
                       tmp[5],
                       tmp[6],
                       tmp[7],
                       tmp[8],
                       tmp[9],
                       tmp[10],
                       tmp[11],
                       tmp[12] );
    for (int i = 0; i < num && i < 13; i++)
        ans |= lookupMountSize( tmp[i] );
    return ans;
}

void DealPossibleJumpDamage( Unit *un )
{
    float speed  = un->GetVelocity().Magnitude();
    float damage = un->GetJumpStatus().damage+(rand()%100 < 1) ? (rand()%20) : 0;
    static float muld = XMLSupport::parse_float( vs_config->getVariable( "physics", "jump_damage_multiplier", ".1" ) );
    static float maxd = XMLSupport::parse_float( vs_config->getVariable( "physics", "max_jump_damage", "100" ) );
    float dam    = speed*(damage*muld);
    if (dam > maxd) dam = maxd;
    if (dam > 1) {
        un->ApplyDamage( ( un->Position()+un->GetVelocity().Cast() ),
                        un->GetVelocity(),
                        dam,
                        un,
                        GFXColor( ( (float) (rand()%100) )/100,
                                 ( (float) (rand()%100) )/100,
                                 ( (float) (rand()%100) )/100 ), NULL );
        un->SetCurPosition( un->LocalPosition()+( ( (float) rand() )/RAND_MAX )*dam*un->GetVelocity().Cast() );
    }
}

void Enslave( Unit *parent, bool enslave )
{
    unsigned int   i;
    vector< Cargo >ToBeChanged;
    unsigned int   numcargo = parent->numCargo();
    for (i = numcargo; i > 0; ) {
        Cargo *carg = &parent->GetCargo( --i );
        if (enslave) {
            if (carg->GetCategory().find( "Passengers" ) != string::npos && carg->content != "Hitchhiker") {
                ToBeChanged.push_back( *carg );
                parent->RemoveCargo( i, carg->quantity, true );
            }
        } else if (carg->content == "Slaves" || carg->content == "Pilot") {
            ToBeChanged.push_back( *carg );
            parent->RemoveCargo( i, carg->quantity, true );
        }
    }
    unsigned int dummy;
    Cargo *newCarg = UniverseUtil::GetMasterPartList()->GetCargo( enslave ? "Slaves" : "Hitchhiker", dummy );
    if (newCarg) {
        Cargo slave = *newCarg;
        for (i = 0; i < ToBeChanged.size(); ++i) {
            slave.quantity = ToBeChanged[i].quantity;
            while (parent->CanAddCargo( slave ) == false && (--slave.quantity) > 0) {}
            if (slave.quantity)
                if ( parent->CanAddCargo( slave ) )
                    parent->AddCargo( slave, true );
        }
    }
}

