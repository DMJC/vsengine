#ifndef __MESH_IO_H__INCLUDED_
#define __MESH_IO_H__INCLUDED_

#define uint32bit unsigned int
#define float32bit float
#define uchar8bit unsigned char

#ifdef DEFINE_BLENDFUNC
enum BLENDFUNC
{
    ZERO         =1,
    ONE          =2,
    SRCCOLOR     =3,
    INVSRCCOLOR  =4,
    SRCALPHA     =5,
    INVSRCALPHA  =6,
    DESTALPHA    =7,
    INVDESTALPHA =8,
    DESTCOLOR    =9,
    INVDESTCOLOR =10,
    SRCALPHASAT  =11,
    CONSTALPHA   =12,
    INVCONSTALPHA=13,
    CONSTCOLOR   =14,
    INVCONSTCOLOR=15
};
#endif

struct Mesh_vec3f
{
    float x;
    float y;
    float z;
};
enum textype
{
    ALPHAMAP,
    ANIMATION,
    TEXTURE,
    TECHNIQUE
};

#endif //__MESH_IO_H__INCLUDED_

