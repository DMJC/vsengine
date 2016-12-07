#include "nebula_generic.h"
#include "vegastrike.h"
#include "vsfilesystem.h"
#include <assert.h>
#include "configxml.h"
#include "vs_globals.h"
#include <sys/stat.h>
#include "xml_support.h"
#undef BOOST_NO_CWCHAR

using namespace XMLSupport;
using namespace NebulaXML;

FOGMODE NebulaXML::parse_fogmode( string val )
{
    if (val == "exp")
        return FOG_EXP;
    else if (val == "exp2")
        return FOG_EXP2;
    else if (val == "linear")
        return FOG_LINEAR;
    else
        return FOG_OFF;
}

void Nebula::beginElement( void *Userdata, const XML_Char *name, const XML_Char **atts )
{
    ( (Nebula*) Userdata )->beginElem( std::string( name ), AttributeList( atts ) );
}

static void Nebula_endElement( void *Userdata, const XML_Char* ) {}

void Nebula::beginElem( const std::string &name, const AttributeList &atts )
{
    Names elem = (Names) element_map.lookup( name );
    AttributeList::const_iterator iter;
    switch (elem)
    {
    case UNKNOWN:
        break;
    case NEBULA:
        fogme   = true;
        explosiontime = 0;
        index   = 0;
        fogmode = FOG_LINEAR;
        for (iter = atts.begin(); iter != atts.end(); iter++) {
            switch ( attribute_map.lookup( (*iter).name ) )
            {
            case DENSITY:
                Density = parse_float( (*iter).value );
                break;
            case INDEX:
                index   = parse_int( (*iter).value );
                break;
            case MODE:
                fogmode = parse_fogmode( (*iter).value );
                break;
            case EXPLOSIONTIME:
                explosiontime = parse_float( (*iter).value );
                break;
            case FOGTHIS:
                fogme = parse_bool( (*iter).value );
                break;
            }
        }
        break;
    case COLOR:
        for (iter = atts.begin(); iter != atts.end(); iter++) {
            switch ( attribute_map.lookup( (*iter).name ) )
            {
            case RED:
                color.i = parse_float( (*iter).value );
                break;
            case GREEN:
                color.j = parse_float( (*iter).value );
                break;
            case BLUE:
                color.k = parse_float( (*iter).value );
                break;
            }
        }
        break;
    case LIMITS:
        for (iter = atts.begin(); iter != atts.end(); iter++) {
            switch ( attribute_map.lookup( (*iter).name ) )
            {
            case NEBNEAR:
                fognear = parse_float( (*iter).value );
                break;
            case NEBFAR:
                fogfar  = parse_float( (*iter).value );
                break;
            }
        }
        break;
    default:
        break;
    }
}

using namespace VSFileSystem;
void Nebula::LoadXML( const char *filename )
{
    VSFile      f;
    VSError     err = f.OpenReadOnly( filename, UnitFile );
    static bool usefog     = XMLSupport::parse_bool( vs_config->getVariable( "graphics", "fog", "true" ) );
    if (err > Ok || !usefog) {
        if (err <= Ok)
            f.Close();
        else
            VSFileSystem::vs_fprintf( stderr, "\nUnit file %s not found\n", filename );
        fogmode = FOG_OFF;
        return;
    }
    XML_Parser parser = XML_ParserCreate( NULL );
    XML_SetUserData( parser, this );
    XML_SetElementHandler( parser, &Nebula::beginElement, &Nebula_endElement );
    XML_Parse( parser, ( f.ReadFull() ).c_str(), f.Size(), 1 );
    XML_ParserFree( parser );
    f.Close();
}

void Nebula::InitNebula( const char *unitfile, bool SubU, int faction, Flightgroup *fg, int fg_snumber )
{
    fogme     = true;
    string fullpath( unitfile );
    fullpath += ".nebula";

    LoadXML( fullpath.c_str() );
}

Nebula::Nebula( const char *unitfile, bool SubU, int faction, Flightgroup *fg, int fg_snumber ) :
    Unit( unitfile, SubU, faction, string( "" ), fg, fg_snumber )
{
    this->InitNebula( unitfile, SubU, faction, fg, fg_snumber );
}

void Nebula::reactToCollision( Unit *smaller,
                               const QVector &biglocation,
                               const Vector &bignormal,
                               const QVector &smalllocation,
                               const Vector &smallnormal,
                               float dist )
{
    if (fogme)
        SetNebula( this );
    smaller->SetNebula( this );
}

void Nebula::UpdatePhysics2( const Transformation &trans,
                             const Transformation &old_physical_state,
                             const Vector &accel,
                             float difficulty,
                             const Matrix &transmat,
                             const Vector &CumulativeVelocity,
                             bool ResolveLast,
                             UnitCollection *uc )
{
    Unit::UpdatePhysics2( trans, old_physical_state, accel, difficulty, transmat, CumulativeVelocity, ResolveLast, uc );
}

