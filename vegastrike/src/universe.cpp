/*
 * Vega Strike
 * Copyright (C) 2001-2002 Daniel Horn & Alan Shieh
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
#include <stdio.h>
#include <fcntl.h>
#include "gfxlib.h"
#include "universe.h"
#include "lin_time.h"
#include "in.h"
#include "gfx/aux_texture.h"
#include "profile.h"
#include "gfx/cockpit.h"
#include "cmd/weapon_xml.h"
#include "galaxy_xml.h"
#include <algorithm>
#include "config_xml.h"
#include "vs_globals.h"
#include "xml_support.h"
#include "audiolib.h"
#include "cmd/script/mission.h"
#include "cmd/unit.h"
#include "in_kb.h"
#include "in_kb_data.h"
#include "in_main.h"
#if defined (__APPLE__)
#import <sys/param.h>
#endif
#include "savegame.h"
#include "gfx/screenshot.h"
#include "universe_util.h"

#include <algorithm>
#include <string>
#include <vector>

#include "options.h"

///Decides whether to toast the jump star from the cache
using std::string;
using std::vector;
using std::find;

extern void CacheJumpStar( bool );
extern void SortStarSystems( vector< StarSystem* > &ss, StarSystem *drawn );
StarSystem* GameUniverse::Init( string systemfile, const Vector &centr, const string planetname )
{
    static bool js = true;
    if (js) {
        js = false;
        LoadWeapons( VSFileSystem::weapon_list.c_str() );
        CacheJumpStar( false );
    }
    return this->Universe::Init( systemfile, centr, planetname );
}

extern void bootstrap_first_loop();

void GameUniverse::Init( int argc, char **argv, const char *galaxy )
{
    current_cockpit = 0;
    //Select drivers
#if defined (__APPLE__)
    //get the current working directory so when glut trashes it we can restore.
    char pwd[MAXPATHLEN];
    getcwd( pwd, MAXPATHLEN );
#endif
    GFXInit( argc, argv );
#if defined (__APPLE__)
    //Restore it
    chdir( pwd );
#endif
    StartGFX();
    InitInput();

    hud_camera = Camera();

    //Hasten splash screen loading, to cover up lengthy universe initialization
    bootstrap_first_loop();

    this->Universe::Init( galaxy );
}

GameUniverse::GameUniverse( int argc, char **argv, const char *galaxy )
{
    this->Init( argc, argv, galaxy );
    is_server = false;
}

GameUniverse::GameUniverse() : Universe()
{}

GameUniverse::~GameUniverse()
{
    DeInitInput();
    GFXShutdown();
}

//sets up all the stuff... in this case the ships to be rendered

void GameUniverse::SetupCockpits( vector< string >playerNames )
{
    for (unsigned int i = 0; i < playerNames.size(); ++i) {
        cockpit.push_back( NULL );
        cockpit.back() = new GameCockpit( "", NULL, playerNames[i] );
    }
}

void GameUniverse::activateLightMap( int stage )
{
    getActiveStarSystem( 0 )->activateLightMap( stage );
}

Texture* GameUniverse::getLightMap()
{
    return getActiveStarSystem( 0 )->getLightMap();
}

void GameUniverse::StartGFX()
{
    GFXBeginScene();
    GFXMaterial mat;
    setMaterialAmbient( mat, 1.0, 1.0, 1.0, 1.0 );
    setMaterialDiffuse( mat, 1.0, 1.0, 1.0, 1.0 );
    setMaterialSpecular( mat, 1.0, 1.0, 1.0, 1.0 );
    setMaterialEmissive( mat, 0.0, 0.0, 0.0, 1.0 );
    mat.power = 60.0F;
    unsigned int tmp;
    GFXSetMaterial( tmp, mat );
    GFXSelectMaterial( tmp );
    int ligh;
    GFXCreateLightContext( ligh );
    GFXSetLightContext( ligh );
    GFXLightContextAmbient( GFXColor( 0, 0, 0, 1 ) );
    GFXEndScene();
}

void GameUniverse::Loop( void main_loop() )
{
    GFXLoop( main_loop );
}

void CalculateCoords( unsigned int i, unsigned int size, float &x, float &y, float &w, float &h )
{
    if (size <= 1) {
        x = y = 0;
        w = h = 1;
        return;
    }
    if ( size <= 3 || i < (size/2) ) {
        y = 0;
        h = 1;
        w = 1./( (float) size );
        x = ( (float) i )/size;
        if (size > 3)
            h = .5;
    }
    if (size > 3) {
        if (i > size/2) {
            y = .5;
            h = .5;
            x = ( (float) i-(size/2) )/(size-size/2);
            w = 1/(size-size/2);
        }
    }
}

extern bool RefreshGUI();
extern float rand01();
extern int timecount;

inline void loadsounds( const string &str, const int max, soundArray &snds, bool loop = false )
{
    char addstr[2] = {'\0'};
    snds.allocate( max );
    for (int i = 0; i < max; ++i) {
        addstr[0] = '1'+i;
        string mynewstr = str;
        while (1) {
            std::string::size_type found = mynewstr.find( '?' );
            if (found != std::string::npos) {
                mynewstr[found] = addstr[0];
            } else {
                break;
            }
        }
        snds.ptr[i].loadsound( mynewstr, loop );
    }
}

static void UpdateTimeCompressionSounds()
{
    static int lasttimecompress = 0;
    if ( (timecount != lasttimecompress) && (game_options.compress_max > 0) ) {
        static bool inittimecompresssounds = false;
        static soundArray loop_snds;
        static soundArray burst_snds;
        static soundArray end_snds;
        if (inittimecompresssounds == false) {
            loadsounds( game_options.compress_loop, game_options.compress_max, loop_snds, true );
            loadsounds( game_options.compress_stop, game_options.compress_max, end_snds );
            loadsounds( game_options.compress_change, game_options.compress_max, burst_snds );
            inittimecompresssounds = true;
        }
        int soundfile     = (timecount-1)/game_options.compress_interval;
        int lastsoundfile = (lasttimecompress-1)/game_options.compress_interval;
        if (timecount > 0 && lasttimecompress >= 0) {
            if ( (soundfile+1) >= game_options.compress_max ) {
                burst_snds.ptr[game_options.compress_max-1].playsound();
            } else {
                if ( lasttimecompress > 0 && loop_snds.ptr[lastsoundfile].sound >= 0
                    && AUDIsPlaying( loop_snds.ptr[lastsoundfile].sound ) )
                    AUDStopPlaying( loop_snds.ptr[lastsoundfile].sound );
                loop_snds.ptr[soundfile].playsound();
                burst_snds.ptr[soundfile].playsound();
            }
        } else if (lasttimecompress > 0 && timecount == 0) {
            for (int i = 0; i < game_options.compress_max; ++i)
                if ( loop_snds.ptr[i].sound >= 0 && AUDIsPlaying( loop_snds.ptr[i].sound ) )
                    AUDStopPlaying( loop_snds.ptr[i].sound );
            if (lastsoundfile >= game_options.compress_max)
                end_snds.ptr[game_options.compress_max-1].playsound();
            else
                end_snds.ptr[lastsoundfile].playsound();
        }
        lasttimecompress = timecount;
    }
}

extern bool screenshotkey;

extern int getmicrosleep();
void GameUniverse::StartDraw()
{
#ifndef WIN32
    RESETTIME();
#endif
    GFXBeginScene();
    size_t i;
    StarSystem  *lastStarSystem = NULL;
    for (i = 0; i < cockpit.size(); ++i) {
        SetActiveCockpit( i );
        float x, y, w, h;
        CalculateCoords( i, cockpit.size(), x, y, w, h );
        AccessCamera()->SetSubwindow( x, y, w, h );
        if (cockpit.size() > 1 && AccessCockpit( i )->activeStarSystem != lastStarSystem) {
            active_star_system[0]->SwapOut();
            lastStarSystem = AccessCockpit()->activeStarSystem;
            active_star_system[0] = lastStarSystem;
            lastStarSystem->SwapIn();
        }
        AccessCockpit()->SelectProperCamera();
        if (cockpit.size() > 0)
            AccessCamera()->UpdateGFX();
        if ( !RefreshGUI() && !UniverseUtil::isSplashScreenShowing() )
            activeStarSystem()->Draw();
        AccessCamera()->SetSubwindow( 0, 0, 1, 1 );
    }
    UpdateTime();
    UpdateTimeCompressionSounds();
    _Universe->SetActiveCockpit( ( (int) ( rand01()*cockpit.size() ) )%cockpit.size() );
    for (i = 0; i < star_system.size() && i < game_options.NumRunningSystems; ++i)
        star_system[i]->Update( (i == 0) ? 1 : game_options.InactiveSystemTime/i, true );
    StarSystem::ProcessPendingJumps();
    for (i = 0; i < cockpit.size(); ++i) {
        SetActiveCockpit( i );
        pushActiveStarSystem( AccessCockpit( i )->activeStarSystem );
        ProcessInput( i );                       //input neesd to be taken care of;
        popActiveStarSystem();
    }
    if (screenshotkey) {
        KBData b;
        Screenshot( b, PRESS );
        screenshotkey = false;
    }
    GFXEndScene();
    //so we don't starve the audio thread
    micro_sleep( getmicrosleep() );

    //remove systems not recently visited?
    static int sorttime = 0;
    if (game_options.garbagecollectfrequency != 0) {
        //don't want to delete something when there is something pending to jump therexo
        if ( PendingJumpsEmpty() ) {
            if ( (++sorttime)%game_options.garbagecollectfrequency == 1 ) {
                SortStarSystems( star_system, active_star_system.back() );
                if (star_system.size() > game_options.numoldsystems && game_options.deleteoldsystems) {
                    if ( std::find( active_star_system.begin(), active_star_system.end(),
                                   star_system.back() ) == active_star_system.end() ) {
                        delete star_system.back();
                        star_system.pop_back();
                    } else {
                        VSFileSystem::vs_fprintf( stderr, "error with active star system list\n" );
                    }
                }
            }
        }
    }
}

void GameUniverse::WriteSaveGame( bool auto_save )
{
    for (unsigned int i = 0; i < cockpit.size(); ++i) {
        if ( AccessCockpit( i ) ) {
            ::WriteSaveGame( AccessCockpit( i ), auto_save );
#if 0
            if ( AccessCockpit( i )->GetParent() )
                if (AccessCockpit( i )->GetParent()->GetHull() > 0) {
                    AccessCockpit( i )->savegame->WriteSaveGame( AccessCockpit(
                                                                    i )->activeStarSystem->getFileName().c_str(),
                                                                AccessCockpit( i )->GetParent()->Position(), AccessCockpit(
                                                                    i )->credits, AccessCockpit( i )->GetUnitFileName() );
                    AccessCockpit( i )->GetParent()->WriteUnit( AccessCockpit( i )->GetUnitModifications().c_str() );
                }

#endif

        }
    }
}

extern StarSystem * GetLoadedStarSystem( const char *system );

StarSystem* GameUniverse::GenerateStarSystem( const char *file, const char *jumpback, Vector center )
{
    StarSystem *tmpcache;
    if ( ( tmpcache = GetLoadedStarSystem( file ) ) )
        return tmpcache;
    this->Generate1( file, jumpback );
    StarSystem *ss = new GameStarSystem( file, center );
    this->Generate2( ss );
    return ss;
}
