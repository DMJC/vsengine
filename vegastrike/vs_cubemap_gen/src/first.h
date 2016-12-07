#ifndef __FIRST_H__
#define __FIRST_H__
/* Always include this file first */


//When including windows.h, it must come before other headers;
//but you should tell VCC not to generate min and max macros...
#ifdef WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

//After windows.h, we can include algorithm by default, as it
//has things that are used almost universally, like std::min/max
#include <algorithm>
using std::min;
using std::max;
#ifdef abs
#undef abs
#endif
template < typename T >
inline T operator abs( T const & t )
{
    return t < t(0) ? -t : t;
}

//and might as well include math.h; we'll need it all over the place
#include "math.h"

//These handy templates save us a lot of coding operators. Just define
//assignment arithmetic operators, and these others are auto-generated
template < typename T >
inline T operator+( T const & a, T const & b )
{
    return T(a) += b;
}
template < typename T >
inline T operator-( T const & a, T const & b )
{
    return T(a) -= b;
}

//another thing we need universally is errors.h, as it handles asserts, exceptions and logs
#include "errors/errors.h"

//and finally units, as everything uses parameters, and all parameters should have units
#include "units/number.h"
#include "units/radians.h"
#include "units/steradians.h"
#include "units/shininess.h"


#endif


