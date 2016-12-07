#include "vegastrike.h"
#include <vector>
#include "beam.h"
#include "unit_generic.h"
//#include "unit_collide.h"
#include "images.h"

Beam::Beam( const Transformation &trans, const weapon_info &clne, void *own, Unit *self, int sound ) : vlist( NULL )
    , Col( clne.r, clne.g, clne.b, clne.a )
{
    VSCONSTRUCT2( 'B' )
    listen_to_owner = false;     //warning this line of code is also present in beam.cpp change one, change ALL

    Init( trans, clne, own, self );
    impact = UNSTABLE;
}

Beam::~Beam()
{
    VSDESTRUCT2
    //VSFileSystem::vs_fprintf (stderr,"Deleting %x",this);
#ifdef BEAMCOLQ
    RemoveFromSystem( true );
#endif
//delete vlist;  // Do not delete shared vlist.
}

void Beam::Draw( const Transformation &trans, const Matrix &m, Unit *targ, float tracking_cone )
{
    //hope that the correct transformation is on teh stack
}

void Beam::ProcessDrawQueue() {}

