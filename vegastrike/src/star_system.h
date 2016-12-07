#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <expat.h>
#include "star_system_generic.h"
#include "gfxlib.h"
#include "gfxlib_struct.h"
class ClickList;
class TextPlane;

class Texture;
class Background;
class Terrain;
class ContinuousTerrain;
class Atmosphere;
/**
 * Star System
 * Scene management for a star system
 * Per-Frame Drawing & Physics simulation
 **/
class GameStarSystem : public StarSystem
{
private:
/// Objects subject to global gravitron physics (disabled)
///The background associated with this system
    Background *bg;
///The Light Map corresponding for the BP for spheremapping
    Texture    *LightMap[6];
//vector <class MissileEffect *> dischargedMissiles;
public:
    virtual ~GameStarSystem();
    GameStarSystem( const char *filename, const Vector &centr = Vector( 0, 0, 0 ), const float timeofyear = 0 );
//void UpdateUnitPhysics(bool firstframe);
//class CollideTable *collidetable;
//class bolt_draw *bolts;
    Background * getBackground()
    {
        return bg;
    }
///activates the light map texture
    void activateLightMap( int stage = 1 );
    Texture * getLightMap();
    static void DrawJumpStars();
    Terrain * getTerrain( unsigned int which )
    {
        return terrains[which];
    }
    unsigned int numTerrain()
    {
        return terrains.size();
    }
    ContinuousTerrain * getContTerrain( unsigned int which )
    {
        return contterrains[which];
    }
    unsigned int numContTerrain()
    {
        return contterrains.size();
    }
///Loads the star system from an XML file
/// returns xy sorted bounding spheres of all units in current view
    ClickList * getClickList();
///Adds to draw list
///Draws a frame of action, interpolating between physics frames
    void Draw( bool DrawCockpit = true );
/// update a simulation atom ExecuteDirector must be false if star system is just loaded before mission is loaded
    void Update( float priority, bool executeDirector );
///re-enables the included lights and terrains
    void SwapIn();
///Disables included lights and terrains
    void SwapOut();
//bool JumpTo (Unit * unit, Unit * jumppoint, const std::string &system);
    virtual void VolitalizeJumpAnimation( const int ani );
    virtual void DoJumpingComeSightAndSound( Unit *un );
    virtual int DoJumpingLeaveSightAndSound( Unit *un );
    friend class Atmosphere;
    void createBackground( StarSystem::StarXML *xml );
};
#endif

