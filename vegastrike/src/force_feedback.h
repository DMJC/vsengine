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
 *  Force Feedback support by Alexander Rawass <alexannika@users.sourceforge.net>
 */

//#define  HAVE_FORCE_FEEDBACK 1

#ifndef _FORCE_FEEDBACK_H_
#define _FORCE_FEEDBACK_H_
#ifndef _WIN32
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#endif
#include <stdio.h>

#if HAVE_FORCE_FEEDBACK

#include <linux/input.h>

#define BITS_PER_LONG (sizeof (long)*8)
#define OFF( x ) ( (x)%BITS_PER_LONG )
#define BIT( x ) ( 1UL<<OFF( x ) )
#define LONG( x ) ( (x)/BITS_PER_LONG )
#define test_bit( bit, array ) ( ( array[LONG( bit )]>>OFF( bit ) )&1 )

#define _is( x ) ( (int) ( 3.2768*( (float) x ) ) )

#endif //have_force_feedback

#define ALL_EFFECTS 1

enum vseffects
{
    eff_speed_damper=0,     //the higher the speed, the more damped
    eff_ab_wiggle_x, eff_ab_wiggle_y, eff_ab_jerk,     //afterburner on
    eff_ab_off_x, eff_ab_off_y,     //afterburner off
    eff_laser_jerk, eff_laser_vibrate,     //laser fired
#if ALL_EFFECTS
    eff_beam_on, eff_beam_off,     //beam
    eff_missile_jerk, eff_missile_vibrate,     //missile
    eff_hit_jerk, eff_hit_vibrate,     //shield hits
#endif
    eff_force     //additional force
};

#if ALL_EFFECTS
#define N_EFFECTS 15
#else
#define N_EFFECTS 9
#endif

class ForceFeedback
{
public: ForceFeedback();
    ~ForceFeedback();

    bool haveFF();

    void playDurationEffect( unsigned int eff_nr, bool activate );
    void playShortEffect( unsigned int eff_nr );

    void playHit( float angle, float strength );
    void updateForce( float angle, float strength );
    void updateSpeedEffect( float strength );
    void playAfterburner( bool activate );
    void playLaser();

private:
    bool have_ff;

#if HAVE_FORCE_FEEDBACK
private:
    void init();

    void init_bogus( int i );
    void playEffect( unsigned int eff_nr );
    void stopEffect( unsigned int eff_nr );

    int device_nr;

    struct ff_effect   effects[N_EFFECTS];
    struct input_event play, stop;
    int    ff_fd;
    unsigned long features[4];
    int    n_effects;   /* Number of effects the device can play at the same time */

    double eff_last_time[N_EFFECTS];

    double min_effect_time;

    bool   is_played[N_EFFECTS];
#endif //have_force_feedback
};

#endif //_FORCE_FEEDBACK_H_

