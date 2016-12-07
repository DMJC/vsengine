/*
 * Vega Strike
 * Copyright (C) 2003 Mike Byron
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

#include "vegastrike.h"

#include "simplepicker.h"

static const int CHILD_VECTOR_RESERVE = 20;         //Make sure we don't get many re-alloc's.

//Add a child to the list of children of this cell.
void SimplePickerCell::addChild( SimplePickerCell *c )
{
    createEmptyChildList();

    m_children->addCell( c );
}

//Make sure there is an empty list for children.
SimplePickerCells* SimplePickerCell::createEmptyChildList( void )
{
    if (m_children == NULL)
        m_children = new SimplePickerCells;
    return m_children;
}

//Constructor.
SimplePickerCell::SimplePickerCell( const std::string &t, const std::string &id, const GFXColor &c, int tag ) :
    m_text( t )
    , m_id( id )
    , m_textColor( c )
    , m_tag( tag )
    , m_children( NULL )
{}

//Destructor.
SimplePickerCell::~SimplePickerCell( void )
{
    if (m_children != NULL)
        delete m_children;
}

SimplePickerCell&SimplePickerCell::operator=( const SimplePickerCell &cell )
{
    m_text      = cell.m_text;
    m_id        = cell.m_id;
    m_textColor = cell.m_textColor;
    m_tag       = cell.m_tag;
    m_children  = NULL;
    if (cell.m_children != NULL)
        //Need to make a copy of the children.
        m_children = new SimplePickerCells( *cell.m_children );
    return *this;
}

SimplePickerCell::SimplePickerCell( const SimplePickerCell &cell )
{
    *this = cell;
}

////////////////////////////////////////////////////////////////////////////

//Constructor.
SimplePickerCells::SimplePickerCells( void )
{
    m_cells.reserve( CHILD_VECTOR_RESERVE );
}

void SimplePickerCells::clear( void )
{
    for (size_t i = 0; i < m_cells.size(); ++i)
        delete m_cells[i];
    m_cells.clear();
}

////////////////////////////////////////////////////////////////////////////

//Clear out all the cells.
void SimplePicker::clear( void )
{
    m_cellPressed     = NULL;
    m_selectedCell    = NULL;
    m_highlightedCell = NULL;

    static_cast< SimplePickerCells* > (m_cells)->clear();

    setMustRecalc();
}

//Constructor.
SimplePicker::SimplePicker( void )
{
    m_cells = new SimplePickerCells();
}

SimplePicker::~SimplePicker( void )
{
    clear();
}

