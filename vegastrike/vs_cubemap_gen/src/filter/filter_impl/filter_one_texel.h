#ifndef __FILTER_ONE_TEX_H__
#define __FILTER_ONE_TEX_H__

/*
* This class is a functor that is created for each texel of the target texture. It's operator()() takes a ray
* as input and returns a color. Computing this color is not trivial, however: It must iterate trough the source
* texels within a given angular radius of the ray, and accumulate light and "weights". The weight for each
* source texel is a product of its filter angle based weight --Phong: weight = pow( cos(angle), shininess )--,
* and the solid angle of that source texel, as perceived from the center of the cube.
*/

class cube;
#include "../../units/radians.h"
#include "../../units/steradians.h"


class filter_one_texel
{
    mem_tex<S> const & src_tex_;
    Shininess          shininess_;
    void               init_constants();
    Radians            max_radius_;
    float              cosa_;
    float              sina_;
    dRGBAcol           accumulator; //weights accumulated in alpha channel
    void plane_min_max( float len_sqr, float x, float y, float& minx, float& maxx,  float& miny,  float& maxy );
public:
    virtual ~filter_one_texel();
    filter_one_texel
    (
        mem_tex<S> const & source
      , Shininess const & shininess
    )
    : source_(source)
    , shininess_(shininess)
    {
        init_constants();
    }
    fRGBAcol operator()( fvector const * ray );
};


#endif


