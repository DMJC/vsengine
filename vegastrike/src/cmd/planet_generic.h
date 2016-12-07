#ifndef __PLANETGENERIC_H
#define __PLANETGENERIC_H

#include "unit_generic.h"
#include "ai/order.h"
#include "configxml.h"
#include "gfxlib_struct.h"
#include "images.h"

class Atmosphere;
class PlanetaryTransform;
class ContinuousTerrain;

class PlanetaryOrbit : public Order
{
private:
    double  velocity;
    double  theta;
    double  inittheta;

    QVector x_size;
    QVector y_size;
    QVector focus;
#define ORBIT_PRIORITY 8
#define NUM_ORBIT_AVERAGE (SIM_QUEUE_SIZE/ORBIT_PRIORITY)
    QVector orbiting_average[NUM_ORBIT_AVERAGE];
    float   orbiting_last_simatom;
    int     current_orbit_frame;
    bool    orbit_list_filled;
protected:
///A vector containing all lihgts currently activated on current planet
    std::vector< int >lights;

public: PlanetaryOrbit( Unit *p,
                        double velocity,
                        double initpos,
                        const QVector &x_axis,
                        const QVector &y_axis,
                        const QVector &Centre,
                        Unit *target = NULL );
    ~PlanetaryOrbit();
    void Execute();
};

class Planet : public Unit
{
protected:
    PlanetaryTransform *terraintrans;
    Atmosphere *atmosphere;
    ContinuousTerrain  *terrain;
    Vector TerrainUp;
    Vector TerrainH;
    bool   inside;
    bool   atmospheric; //then users can go inside!
    float  radius;
    float  gravity;
    UnitCollection    insiders;
    std::vector< int >lights;
protected:
/// default constructor - only to be called by UnitFactory
    Planet();
/// constructor - only to be called by UnitFactory
    Planet( QVector x,
            QVector y,
            float vely,
            const Vector &rotvel,
            float pos,
            float gravity,
            float radius,
            const string &filename,
            const string &technique,
            const string &unitname,
            const vector< string > &dest,
            const QVector &orbitcent,
            Unit *parent,
            int faction,
            string fullname,
            bool inside_out = false,
            unsigned int lights_num = 0 );
    void InitPlanet( QVector x,
                     QVector y,
                     float vely,
                     const Vector &rotvel,
                     float pos,
                     float gravity,
                     float radius,
                     const string &filename,
                     const string &technique,
                     const string &unitname,
                     const vector< string > &dest,
                     const QVector &orbitcent,
                     Unit *parent,
                     int faction,
                     string fullname,
                     bool inside_out,
                     unsigned int lights_num );

    friend class UnitFactory;
    Planet( std::vector< Mesh* >m, bool b, int i ) : Unit( m, b, i ) {}
public:
    UnitCollection satellites;
    virtual ~Planet();
    inline const float getRadius() const { return radius; }
    virtual Vector AddSpaceElevator( const std::string &name, const std::string &faction, char direction );
    virtual void AddFog( const vector< AtmosphericFogMesh > &meshes, bool optical_illusion ) {}
    virtual void AddAtmosphere( const std::string &texture,
                                float radius,
                                BLENDFUNC blendSrc,
                                BLENDFUNC blendDst,
                                bool inside_out ) {}
    virtual void AddRing( const std::string &texture,
                          float iradius,
                          float oradius,
                          const QVector &r,
                          const QVector &s,
                          int slices,
                          int numwrapx,
                          int numwrapy,
                          BLENDFUNC blendSrc,
                          BLENDFUNC blendDst ) {}
    virtual void AddCity( const std::string &texture,
                          float radius,
                          int numwrapx,
                          int numwrapy,
                          BLENDFUNC blendSrc,
                          BLENDFUNC blendDst,
                          bool inside_out = false,
                          bool reverse_normals = true ) {}
    virtual void DisableLights() {}
    virtual void EnableLights() {}
    void AddSatellite( Unit *orbiter );
    void endElement();
    string getCargoUnitName() const
    {
        return getFullname();
    }
    string getHumanReadablePlanetType() const;
    Unit * beginElement( QVector x,
                         QVector y,
                         float vely,
                         const Vector &rotvel,
                         float pos,
                         float gravity,
                         float radius,
                         const string &filename,
                         const string &technique,
                         const string &unitname,
                         BLENDFUNC blendsrc,
                         BLENDFUNC blenddst,
                         const vector< string > &dest,
                         int level,
                         const GFXMaterial &ourmat,
                         const std::vector< GFXLightLocal > &ligh,
                         bool isunit,
                         int faction,
                         string fullname,
                         bool inside_out );
    Planet * GetTopPlanet( int level );
    virtual enum clsptr isUnit() const
    {
        return PLANETPTR;
    }
    virtual void Draw( const Transformation &quat = identity_transformation, const Matrix &m = identity_matrix ) {}
    virtual void DrawTerrain() {}
    static void ProcessTerrains() {}
    virtual void Kill( bool erasefromsave = false );

    virtual PlanetaryTransform * setTerrain( ContinuousTerrain*, float ratiox, int numwraps, float scaleatmos )
    {
        return NULL;
    }
    virtual ContinuousTerrain * getTerrain( PlanetaryTransform* &t )
    {
        return NULL;
    }
    virtual void setAtmosphere( Atmosphere* ) {}
    virtual Atmosphere * getAtmosphere()
    {
        return NULL;
    }
    virtual void reactToCollision( Unit *smaller,
                                   const QVector &biglocation,
                                   const Vector &bignormal,
                                   const QVector &smalllocation,
                                   const Vector &smallnormal,
                                   float dist )
    {
        this->Unit::reactToCollision( smaller, biglocation, bignormal, smalllocation, smallnormal, dist );
    }

    class PlanetIterator
    {
public: PlanetIterator( Planet *p )
        {
            localCollection.append( p );
            pos = localCollection.createIterator();
        }
        ~PlanetIterator() {}
        void preinsert( Unit *unit )
        {
            abort();
        }
        void postinsert( Unit *unit )
        {
            abort();
        }
        void remove()
        {
            abort();
        }
        inline Unit * current()
        {
            if ( !pos.isDone() )
                return *pos;
            return NULL;
        }
        void advance()
        {
            if (current() != NULL) {
                Unit *cur = *pos;
                if (cur->isUnit() == PLANETPTR)
                    for (un_iter tmp( ( (Planet*) cur )->satellites.createIterator() ); !tmp.isDone(); ++tmp)
                        localCollection.append( (*tmp) );
                ++pos;
            }
        }
        inline PlanetIterator& operator++()
        {
            advance();
            return *this;
        }
        inline Unit* operator*()
        {
            return current();
        }
private:
        inline un_iter operator++( int )
        {
            abort();
        }
        UnitCollection localCollection;
        un_iter pos;
    };
    PlanetIterator createIterator()
    {
        return PlanetIterator( this );
    }
    bool isAtmospheric() const
    {
        return hasLights() || atmospheric;
    }

    bool hasLights() const
    {
        return !lights.empty();
    }
    const std::vector< int >& activeLights()
    {
        return lights;
    }

    friend class Planet::PlanetIterator;
    friend class PlanetaryOrbit;

private:
/// copy constructor forbidden
    Planet( const Planet& );
/// assignment operator forbidden
    Planet& operator=( const Planet& );
};

#endif

