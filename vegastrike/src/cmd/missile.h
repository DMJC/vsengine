#ifndef MISSILE_H_
#define MISSILE_H_

#include "missile_generic.h"
#include "cmd/unit_util.h"

class GameMissile : public GameUnit< Missile >
{
protected:
/// constructor only to be called by UnitFactory
    GameMissile( const char *filename,
                 int faction,
                 const string &modifications,
                 const float damage,
                 float phasedamage,
                 float time,
                 float radialeffect,
                 float radmult,
                 float detonation_radius ) :
        GameUnit< Missile > ( filename, false, faction, modifications )
    {
        this->InitMissile( time, damage, phasedamage, radialeffect, radmult, detonation_radius, false, -1 );
        static bool missilesparkle = XMLSupport::parse_bool( vs_config->getVariable( "graphics", "missilesparkle", "false" ) );
        if (missilesparkle)
            maxhull *= 4;
    }

    friend class UnitFactory;

public:
    virtual void Kill( bool erase = true )
    {
        Missile::Discharge();
        GameUnit< Missile >::Kill( erase );
    }
    virtual void reactToCollision( Unit *smaller,
                                   const QVector &biglocation,
                                   const Vector &bignormal,
                                   const QVector &smalllocation,
                                   const Vector &smallnormal,
                                   float dist )
    {
        static bool doesmissilebounce = XMLSupport::parse_bool( vs_config->getVariable( "physics", "missile_bounce", "false" ) );
        if (doesmissilebounce)
            GameUnit< Missile >::reactToCollision( smaller, biglocation, bignormal, smalllocation, smallnormal, dist );
        Discharge();
        if (!killed)
            DealDamageToHull( smalllocation.Cast(), hull+1 );      //should kill, applying addmissile effect
    }
    virtual void UpdatePhysics2( const Transformation &trans,
                                 const Transformation &old_physical_state,
                                 const Vector &accel,
                                 float difficulty,
                                 const Matrix &transmat,
                                 const Vector &CumulativeVelocity,
                                 bool ResolveLast,
                                 UnitCollection *uc = NULL )
    {
        Unit *targ;
        if ( ( targ = ( Unit::Target() ) ) )
            if (rand()/( (float) RAND_MAX ) < ( (float) UnitUtil::getECM(targ) )*SIMULATION_ATOM/32768)
                Target( NULL );
        //go wild
        if (retarget == -1) {
            if (targ)
                retarget = 1;
            else
                retarget = 0;
        }
        if (retarget && targ == NULL)
            Target( NULL );
        GameUnit< Missile >::UpdatePhysics2( trans,
                                             old_physical_state,
                                             accel,
                                             difficulty,
                                             transmat,
                                             CumulativeVelocity,
                                             ResolveLast,
                                             uc );
    }

private:
/// default constructor forbidden
    GameMissile();
/// copy constructor forbidden
    GameMissile( const Missile& );
/// assignment operator forbidden
    GameMissile& operator=( const Missile& );
};

#endif

