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

/*
 *  xml Configuration written by Alexander Rawass <alexannika@users.sourceforge.net>
 */

#ifndef _VEGASIMPLECONFIG_H_
#define _VEGASIMPLECONFIG_H_

#include <expat.h>
#include <string>
#include "xml_support.h"
#include "easydom.h"
#include <map>
#include "gfxlib_struct.h"

using std::string;
using std::map;

using XMLSupport::AttributeList;

class vColor
{
public:
    string name;
    float  r, g, b, a;
};

class configNode : public easyDomNode
{
public:
    vColor *color;
};

enum section_t {SECTION_COLOR, SECTION_VAR};

class configNodeFactory : public easyDomFactory< configNode >
{};

class VegaConfig
{
public:
    explicit VegaConfig( const char *configfile );
    virtual ~VegaConfig();
#define MAX_AXIS 32
    int axis_axis[MAX_AXIS];
    int   axis_joy[MAX_AXIS];
    bool  axis_inverse[MAX_AXIS];
#define MAX_HATSWITCHES 16
#define MAX_VALUES 12
    float hatswitch[MAX_HATSWITCHES][MAX_VALUES];
    float hatswitch_margin[MAX_HATSWITCHES];
    int   hatswitch_axis[MAX_HATSWITCHES];
    int   hatswitch_joystick[MAX_HATSWITCHES];
    GFXColor getColor( configNode*node, string name, GFXColor default_color = GFXColor( 1, 1, 1, 1 ) );
    GFXColor getColor( string section, string name, GFXColor default_color = GFXColor( 1, 1, 1, 1 ) );
    inline GFXColor getColor( string name, GFXColor default_color = GFXColor( 1, 1, 1, 1 ) )
    {
        return getColor( "default", name, default_color );
    }
    string getVariable( string section, string name, string defaultvalue );
    string getVariable( string section, string subsection, string name, string defaultvalue );
    configNode * findSection( string section, configNode *startnode );
    configNode * findEntry( string name, configNode *startnode );
    void setVariable( configNode *entry, string value );
    bool setVariable( string section, string name, string value );
    bool setVariable( string section, string subsection, string name, string value );
    easyDomNode * Variables()
    {
        return variables;
    }
    virtual void bindKeys() {}
protected:
    string getVariable( configNode *section, string name, string defaultval );
    configNode *variables;
    configNode *bindings;
    configNode *colors;
    map< string, string >map_variables;
    map< string, vColor >map_colors;
    int hs_value_index;
//vector<vColor *> colors;
    bool checkConfig( configNode *node );
    void doVariables( configNode *node );
    void checkSection( configNode *node, enum section_t section_type );
    void checkVar( configNode *node );
    void doSection( string prefix, configNode *node, enum section_t section_type );
    void doVar( string prefix, configNode *node );
    void doColors( configNode *node );
    bool checkColor( string prefix, configNode *node );
    virtual void doBindings( configNode *node ) {}
    virtual void checkBind( configNode *node ) {}
    virtual void doAxis( configNode *node ) {}
    virtual void checkHatswitch( int nr, configNode *node ) {}
};

#endif //_VEGACONFIG_H_

