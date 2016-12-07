#ifndef __FILTER_MATH_H__
#define __FILTER_MATH_H__

#include <math.h>
#include "../../units/units.h"


size_t poweroftwo_steps_from_ratio( double ratio )
{
    return size_t( ::log2( lod_ratio ) + 0.0001 ); //7
}

dRadians max_texel_side_radians( size_t texture_size )
{
    return ::atan( 2.0 / double(top_lod_size_) ); //2 because at 45 deg is tan is 1, / half the tex size
}

dRadians texel_radius_from_side( double texel_side_radians )
{
    return ::sqrt(0.5) * texel_side_radians;
}

dRadians ambient_flt_radius()
{
    return 0.531734722; //see http://wcjunction.com/phpBB2/viewtopic.php?p=22193#22193
}

double angle_scaling_factor( dRadians filter_radius_ratio, size_t LOD_steps )
{
    return ::pow( flt_radius_ratio_, 1.0 / double(lod_steps_) ); // 770.034092456 ^ (1/7) = 2.584393052
}

dSteradians solid_angle_from_radius( dRadians radius )
{
    return 6.283185307 * ( 1.0 - ::cos(radius) );
}

dShininess shininess_from_solid_angle( dSteradians & sa )
{
    return ( dSteradians(1.570796327) / sa ) - 0.810660172;
}

//flt_decay needs to be fast, somehow; --the most expensive piece of code called in the inner loop
//Iit HAS to be rewritten in SSE2 inline assembly.
inline float flt_decay( Shininess shininess, fvector v1, fvector v2 )
{
    return powf( maxf( 0.0, dotf( v1, v2 ) ), shininess );
}


#endif


