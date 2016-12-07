#include "cmd/unit_generic.h"
#include "config_xml.h"
#include "xml_support.h"
#include "vs_globals.h"
#include "universe_util.h"
#include "gldrv/winsys.h"
#include "options.h"



static inline float vs_fmin( float a, float b )
{
    return (a < b) ? a : b;
}
static inline float vs_fmax( float a, float b )
{
    return (a > b) ? a : b;
}

class ShipCommands
{
    Functor< ShipCommands > *csetkps;
    Functor< ShipCommands > *cleft;
    Functor< ShipCommands > *cright;
    Functor< ShipCommands > *cup;
    Functor< ShipCommands > *cdown;
    Functor< ShipCommands > *cslide;
    Functor< ShipCommands > *cfire;
    Functor< ShipCommands > *croll;
    Functor< ShipCommands > *cpymenu;
    bool broll;
    bool bleft;
    bool bright;
    bool bup;
    bool bdown;
public:
    virtual ~ShipCommands()
    {
        CommandInterpretor->remCommand( cpymenu );
        CommandInterpretor->remCommand( csetkps );
    }
    ShipCommands()
    {
        //create some functors, register them with the command interp {{{
        cpymenu = new Functor< ShipCommands > ( this, &ShipCommands::pymenu );
        CommandInterpretor->addCommand( cpymenu, "pymenu" );
        csetkps = new Functor< ShipCommands > ( this, &ShipCommands::setkps );
        CommandInterpretor->addCommand( csetkps, "setspeed" );
        //}}}
        //set some local bools false {{{
        broll  = false;
        bleft  = false;
        bright = false;
        bup    = false;
        bdown  = false;
        //}}}
        //a test menu {{{
        {
            static char const python_test[20] = "python test";
            static char const test_string[40] = "This is a test of the menusystem";
            menu *m = new menu( python_test, test_string, "\r\n" );
            CommandInterpretor->addMenu( m );
            {
                mItem *mi = new mItem;
                mi->autoreprint = true;
                mi->Name.append( "1" );                       //argument to access menu
                mi->display.append( "Python One Line input" );                       //menu's display name
                mi->func2call.append( "python" );
                mi->inputbit = true;                         //set single-line input mode
                mi->selectstring.append( "Type a single line of Python" );                       //call function "Display" with this string
                CommandInterpretor->addMenuItem( mi );
            }
            {
                mItem *mi = new mItem;
                mi->autoreprint = true;                         //auto-re-print the
                //menu after this menuitem is finished
                mi->Name.append( "2" );                       //argument to access menu
                mi->display.append( "(Python Multi-Line input)" );                       //menu's display name
                mi->func2call.append( "python" );                       //call this function when this menuitem is called and input is all recieved, user input is appened with a space, along with the action string if there is one. (string generated: "func2call action userinput")
                mi->inputbit2 = true;                         //set single-line input mode
                mi->selectstring.append( "Type multiple lines of python input. Use <ENTER> on a line ALONE to finish" );                       //Call function "Display" with this string
                CommandInterpretor->addMenuItem( mi );
            }
        }
    }
    void pymenu();
    void left( bool *isKeyDown );
    void right( bool *isKeyDown );
    void up( bool *isKeyDown );
    void down( bool *isKeyDown );
    void roll( bool *isKeyDown );
    void setkps( const char *in );
};
//these _would_ work if the physics routines polled the ship_commands object
//for these bools..
void ShipCommands::pymenu()
{
    std::string response( CommandInterpretor->setMenu( "python test" ) );
    CommandInterpretor->conoutf( response );
}
void ShipCommands::left( bool *isKeyDown )
{
    bleft = isKeyDown;
}
void ShipCommands::right( bool *isKeyDown )
{
    bright = isKeyDown;
}
void ShipCommands::up( bool *isKeyDown )
{
    bup = isKeyDown;
}
void ShipCommands::down( bool *isKeyDown )
{
    bdown = isKeyDown;
}
void ShipCommands::roll( bool *isKeyDown )
{
    broll = isKeyDown;
}

static ShipCommands *ship_commands = NULL;

void ShipCommands::setkps( const char *in )
{
    if (in == NULL) throw "What speed?";
    float kps    = XMLSupport::parse_float( std::string( in ) );
    Unit *player = UniverseUtil::getPlayer();
    if (player) {
        if (game_options.game_speed_lying)
            kps *= game_options.game_speed;
        else
            kps /= game_options.display_in_meters ? 1.0f : 3.6f;
        player->GetComputerData().set_speed = vs_fmin( player->GetComputerData().max_speed(), kps );
    }
}

void InitShipCommands()
{
    if (ship_commands) delete ship_commands;
    ship_commands = new ShipCommands;
}

void UninitShipCommands()
{
    if (ship_commands) delete ship_commands;
    ship_commands = NULL;
}

