#include "cmd/asteroid.h"
#include "cmd/asteroid_generic.h"
#include "cmd/script/flightgroup.h"
#include "cmd/collection.h"
#include "gfx/vec.h"
#include "gfx/quaternion.h"
#include "gfx/matrix.h"
#include "cmd/unit.h"

GameAsteroid::GameAsteroid( const char *filename, int faction, Flightgroup *fg, int fg_snumber,
                            float difficulty ) : GameUnit< Asteroid > ( filename, false, faction, string( "" ), fg, fg_snumber )
{
    Asteroid::Init( difficulty );
}

void GameAsteroid::UpdatePhysics2( const Transformation &trans,
                                   const Transformation &old_physical_state,
                                   const Vector &accel,
                                   float difficulty,
                                   const Matrix &transmat,
                                   const Vector &CumulativeVelocity,
                                   bool ResolveLast,
                                   UnitCollection *uc )
{
    GameUnit< Asteroid >::UpdatePhysics2( trans,
                                          old_physical_state,
                                          accel,
                                          difficulty,
                                          transmat,
                                          CumulativeVelocity,
                                          ResolveLast,
                                          uc );
}

