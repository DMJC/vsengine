/*
 * Vega Strike
 * Copyright (C) 2001-2002 Daniel Horn
 *
 * http://vegastrike.sourceforge.net/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#ifndef LOGO_H_
#define LOGO_H_

#include "matrix.h"
#include "gfxlib.h"
#include "hashtable.h"
#include <vector>

//struct glVertex;
class Mesh;
class Texture;
class Vector;
class Logo
{
    int numlogos;
//glVertex **LogoCorner;
    GFXVertexList *vlist;
    Texture *Decal;
    static Hashtable< int, Logo, 257 >decalHash;
    Logo() {}
protected:
    friend class Mesh;
    int   refcount;   //number of references to draw_queue
    Logo *owner_of_draw_queue;     //owner of the draw_queue
    vector< DrawContext > *draw_queue;
    bool  will_be_drawn;
    void ProcessDrawQueue();
public: Logo( int numberlogos,
              Vector *center,
              Vector *normal,
              float *sizes,
              float *rotations,
              float offset,
              Texture *Dec,
              Vector *Ref );
    Logo( const Logo &rval )
    {
        *this = rval;
    }
    ~Logo();
    void SetDecal( Texture *decal );
    void Draw( const Matrix &m );
};
#endif

