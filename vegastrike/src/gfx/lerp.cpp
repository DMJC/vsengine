#include "lerp.h"

Transformation linear_interpolate_uncapped( const Transformation &A, const Transformation &B, double blend )
{
    Quaternion result;
    const Quaternion &a = A.orientation;
    const Quaternion &b = B.orientation;

    double     f = blend, omf = 1.0-f, f0, f1, sadj=1.0;
    double     cos_omega = DotProduct( a.v, b.v )+a.s*b.s;

    //Adjust signs if necessary.
    if (cos_omega < 0.0) {
        cos_omega = -cos_omega;
        sadj = -1.0;
    }
    if (cos_omega < 0.99) {
        //Do the spherical interp.
        double omega     = acos( cos_omega );
        double isin_omega = 1.0 / sin( omega );
        f0 = sin( omf*omega ) * isin_omega;
        f1 = sin( f*omega ) * isin_omega;
    } else {
        //Quaternions are close; just do straight lerp and avoid division by near-zero.
        f0 = omf;
        f1 = f;
    }
    result.s = a.s*float(f0)+b.s*float(f1*sadj);
    result.v = a.v*float(f0)+b.v*float(f1*sadj);
    result.Normalize();
    
    return Transformation( result, A.position + (B.position - A.position)*f );
}

