#ifndef _NEBULA_GENERIC_H_
#define _NEBULA_GENERIC_H_
#include "unit_generic.h"
#include "xml_support.h"

class Nebula : public Unit
{
protected:
    static void beginElement( void *Userdata, const XML_Char *name, const XML_Char **atts );
    Vector color;
    float  Density;
    float  fognear;
    float  fogfar;
    int    index;
    float  explosiontime;
    enum FOGMODE fogmode;     //0=OFF (I won't use this), 1=EXP, 2=EXP2, 3=LINEAR
    bool   fogme;
    void LoadXML( const char *filename );
    void beginElem( const std::string&, const AttributeList& );
    float  lastfadein;
    float  fadeinvalue;
public:
    void InitNebula( const char *unitfile, bool SubU, int faction, Flightgroup *fg, int fg_snumber );
    float getFade()
    {
        return fadeinvalue;
    }
    virtual void PutInsideCam( int ) {}
    virtual enum clsptr isUnit() const
    {
        return NEBULAPTR;
    }
    virtual void reactToCollision( Unit *smaller,
                                   const QVector &biglocation,
                                   const Vector &bignormal,
                                   const QVector &smalllocation,
                                   const Vector &smallnormal,
                                   float dist );

protected:
/// constructor only to be called by UnitFactory
    Nebula( const char *unitfile, bool SubU, int faction, Flightgroup *fg = NULL, int fg_snumber = 0 );

    friend class UnitFactory;
    Nebula( std::vector< Mesh* >m, bool b, int i ) : Unit( m, b, i ) {}
public:
    virtual void UpdatePhysics2( const Transformation &trans,
                                 const Transformation &old_physical_state,
                                 const Vector &accel,
                                 float difficulty,
                                 const Matrix &transmat,
                                 const Vector &CumulativeVelocity,
                                 bool ResolveLast,
                                 UnitCollection *uc = NULL );

    virtual void SetFogState() {}

protected:
/// default constructor forbidden
    Nebula() {}
/// copy constructor forbidden
//Nebula( const Nebula& );
/// assignment operator forbidden
//Nebula& operator=( const Nebula& );
};

namespace NebulaXML
{
FOGMODE parse_fogmode( string val );

enum Names
{
    UNKNOWN,
    NEBULA,
    RED,
    GREEN,
    BLUE,
    COLOR,
    MODE,
    NEBNEAR,
    NEBFAR,
    DENSITY,
    LIMITS,
    INDEX,
    EXPLOSIONTIME,
    FOGTHIS
};
const unsigned short int MAXENAMES = 4;
const unsigned short int MAXANAMES = 11;

const XMLSupport::EnumMap::Pair element_names[MAXENAMES] = {
    XMLSupport::EnumMap::Pair( "UNKNOWN", UNKNOWN ),
    XMLSupport::EnumMap::Pair( "Nebula",  NEBULA ),
    XMLSupport::EnumMap::Pair( "Color",   COLOR ),
    XMLSupport::EnumMap::Pair( "Limits",  LIMITS ),
};
const XMLSupport::EnumMap::Pair attribute_names[MAXANAMES] = {
    XMLSupport::EnumMap::Pair( "UNKNOWN",       UNKNOWN ),
    XMLSupport::EnumMap::Pair( "Red",           RED ),
    XMLSupport::EnumMap::Pair( "Green",         GREEN ),
    XMLSupport::EnumMap::Pair( "Blue",          BLUE ),
    XMLSupport::EnumMap::Pair( "Near",          NEBNEAR ),
    XMLSupport::EnumMap::Pair( "Far",           NEBFAR ),
    XMLSupport::EnumMap::Pair( "Density",       DENSITY ),
    XMLSupport::EnumMap::Pair( "Mode",          MODE ),
    XMLSupport::EnumMap::Pair( "Index",         INDEX ),
    XMLSupport::EnumMap::Pair( "ExplosionTime", EXPLOSIONTIME ),
    XMLSupport::EnumMap::Pair( "FogThis",       FOGTHIS )
};

const XMLSupport::EnumMap element_map( element_names, MAXENAMES );
const XMLSupport::EnumMap attribute_map( attribute_names, MAXANAMES );
}

#endif

