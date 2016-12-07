#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float huge = .5e38;
int main( int argc, char **argv )
{
    int   i;
    float scalex = 1;
    float scaley = 1;
    float scalez = 1;
    float transx = 0;
    float transy = 0;
    float transz = 0;
    float minx   = huge;
    float miny   = huge;
    float minz   = huge;
    float maxx   = -huge;
    float maxy   = -huge;
    float maxz   = -huge;
    for (i = 0; i < (unsigned int) argc; ++i) {
        char match = 1;
        int  j;
        if (strncmp( argv[i], "-scalex", 7 ) == 0)
            scalex = (float) atof( argv[i]+7 );
        else if (strncmp( argv[i], "-scaley", 7 ) == 0)
            scaley = (float) atof( argv[i]+7 );
        else if (strncmp( argv[i], "-scalez", 7 ) == 0)
            scalez = (float) atof( argv[i]+7 );
        else if (strncmp( argv[i], "-transx", 7 ) == 0)
            transx = (float) atof( argv[i]+7 );
        else if (strncmp( argv[i], "-transy", 7 ) == 0)
            transy = (float) atof( argv[i]+7 );
        else if (strncmp( argv[i], "-transz", 7 ) == 0)
            transz = (float) atof( argv[i]+7 );
        else
            match = 0;
        if (match == 1) {
            for (j = i+1; j < argc; ++j)
                argv[j-1] = argv[j];
            argc--;
            i--;
        }
    }
    printf( "Scaling the mesh to (%f %f %f)\ntranslating to (%f %f %f)\n",
            scalex, scaley, scalez, transx, transy, transz );
    FILE *in  = fopen( argv[1], "rb" );
    FILE *out = fopen( argv[2], "wb" );
    char  line[16384];
    while ( fgets( line, 16384, in ) ) {
        double x = 0, y = 0, z = 0;
        if ( 3 == sscanf( line, "v %lf %lf %lf", &x, &y, &z ) ) {
            if (x < minx)
                minx = x;
            if (y < miny)
                miny = y;
            if (z < minz)
                minz = z;
            if (x > maxx)
                maxx = x;
            if (y > maxy)
                maxy = y;
            if (z > maxz)
                maxz = z;
            x += transx;
            x *= scalex;
            y += transy;
            y *= scaley;
            z += transz;
            z *= scalez;
            fprintf( out, "v %lf %lf %lf\n", x, y, z );
        } else {
            fprintf( out, "%s", line );
        }
    }
    printf( "Translating bounds of\n[(%f %f %f) - (%f %f %f) ]\nto bounds of\n[(%f %f %f) - (%f %f %f)]\n",
           minx, miny, minz, maxx, maxy, maxz,
           scalex*(minx+transx), scaley*(miny+transy), scalez*(minz+transz),
           scalex*(maxx+transx), scaley*(maxy+transy), scalez*(maxz+transz) );
    return 0;
}

