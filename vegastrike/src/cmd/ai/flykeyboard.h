#ifndef _IN_AI_H_
#define _IN_AI_H_
#include "in.h"
#if defined (__APPLE__) || defined (MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include "flybywire.h"

class FlyByKeyboard : public FlyByWire
{
    Order *autopilot;
    Vector axis_key;
    unsigned int last_jumped;
protected:
    enum joy_mode_enum
    {
        joyModeNormal    =0,
        joyModeInertialXY=1,
        joyModeInertialXZ=2,
        joyModeRoll=4,
        joyModeBank=8
    };
    char joy_mode; //do not mix different modes
protected:
    void KeyboardUp( float val );
    void KeyboardRight( float val );
    void KeyboardRollRight( float val );
    float clamp_axis( float v );
    float reduce_axis( float v );
public:
    static void SwitchWebcam( const KBData &, KBSTATE );
    static void SwitchSecured( const KBData &, KBSTATE );
    static void ChangeCommStatus( const KBData &, KBSTATE );
    static void DownFreq( const KBData &, KBSTATE );
    static void UpFreq( const KBData &, KBSTATE );
    static void KSwitchFlightMode( const KBData &, KBSTATE );
    static void KThrustRight( const KBData &, KBSTATE );
    static void KThrustLeft( const KBData &, KBSTATE );
    static void KThrustUp( const KBData &, KBSTATE );
    static void KThrustDown( const KBData &, KBSTATE );
    static void KThrustFront( const KBData &, KBSTATE );
    static void KThrustBack( const KBData &, KBSTATE );
    static void SheltonKey( const KBData &, KBSTATE );
    static void InertialToggleKey( const KBData &, KBSTATE );
    static void InertialPulsorKey( const KBData &, KBSTATE );
    static void JoyInertialXYPulsorKey( const KBData &, KBSTATE );
    static void JoyInertialXZPulsorKey( const KBData &, KBSTATE );
    static void JoyInertialXYToggleKey( const KBData &, KBSTATE );
    static void JoyInertialXZToggleKey( const KBData &, KBSTATE );
    static void JoyRollPulsorKey( const KBData &, KBSTATE );
    static void JoyRollToggleKey( const KBData &, KBSTATE );
    static void JoyBankPulsorKey( const KBData &, KBSTATE );
    static void JoyBankToggleKey( const KBData &, KBSTATE );
    static void StartKey( const KBData &, KBSTATE );
    static void StopKey( const KBData &, KBSTATE );
    static void UpKey( const KBData &, KBSTATE );
    static void DownKey( const KBData &, KBSTATE );
    static void LeftKey( const KBData &, KBSTATE );
    static void RightKey( const KBData &, KBSTATE );
    static void ABKey( const KBData &, KBSTATE );
    static void AccelKey( const KBData &, KBSTATE );
    static void DecelKey( const KBData &, KBSTATE );
    static void RollLeftKey( const KBData &, KBSTATE );
    static void RollRightKey( const KBData &, KBSTATE );
    static void MatchSpeedKey( const KBData &, KBSTATE );
    static void JumpKey( const KBData &, KBSTATE );
    static void AutoKey( const KBData &, KBSTATE );
    static void SwitchCombatModeKey( const KBData &, KBSTATE );
    static void EngageSpecAuto( const KBData &, KBSTATE );
    static void StopAutoKey( const KBData &, KBSTATE );
    static void SetVelocityRefKey( const KBData &, KBSTATE );
    static void SetNullVelocityRefKey( const KBData &, KBSTATE );
    int  whichplayer;
    bool inauto;
    FlyByKeyboard( unsigned int whichplayer );
    virtual void Destroy();
    virtual ~FlyByKeyboard();
    void Execute( bool ); //should we reset our ang velocity
    void Execute();
};

#endif

