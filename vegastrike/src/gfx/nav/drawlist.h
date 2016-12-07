#ifndef _DRAWLIST_H_
#define _DRAWLIST_H_

#include <stdlib.h>
#include <string>
#include "cmd/unit_generic.h"
#include "navscreenoccupied.h"
#include "gui/glut_support.h"

//#include "masks.h"
#include "navscreen.h"
#include "navitemtypes.h"

class navdrawnode
{
public:
    int   type;
    float size;
    float x;
    float y;

    navdrawnode *nextitem;
    Unit *source;

    navdrawnode();
    navdrawnode( int type, float size, float x, float y, navdrawnode *nextitem );
    navdrawnode( int type, float size, float x, float y, Unit *source, navdrawnode *nextitem );
};

void drawdescription( Unit *source,
                      float x,
                      float y,
                      float size_x,
                      float size_y,
                      bool ignore_occupied_areas,
                      navscreenoccupied *screenoccupation,
                      const GFXColor &col );
void drawdescription( string text,
                      float x,
                      float y,
                      float size_x,
                      float size_y,
                      bool ignore_occupied_areas,
                      navscreenoccupied *screenoccupation,
                      const GFXColor &col );

void drawlistitem( int type,
                   float size,
                   float x,
                   float y,
                   Unit *source,
                   navscreenoccupied *screenoccupation,
                   bool inmouserange,
                   bool currentistail,
                   float unselectedalpha,
                   GFXColor *factioncolours );

class navdrawlist       //not really a list... it inserts at head, and reads head first. like a stack, but it isnt popping. its just going through it, and whiping.
{
    int  n_contents;
    bool inmouserange;
    bool localcolours;
    navdrawnode *head;
    navdrawnode *tail;
    GFXColor    *factioncolours;
    navscreenoccupied *screenoccupation;

//this is a restatement of that found in the navscreen
    float screenskipby4[4];     //0 = x-small	1 = x-large	2 = y-small	3 = y-large

//10 sectors for text on the nav screen.
//10 sectors across, divided into 32 sections top/down.

public:
    void insert( int type, float size, float x, float y );
    void insert( int type, float size, float x, float y, Unit *source );
    void wipe();
    void rotate();
    void draw();
    int get_n_contents();
    float unselectedalpha;
    Unit * gettailunit();
    navdrawlist( bool mouse, navscreenoccupied *screenoccupation, GFXColor *factioncolours );
    ~navdrawlist();
};

#endif

