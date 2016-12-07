// -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef VEGASTRIKE_GFX_RADAR_SENSOR_H
#define VEGASTRIKE_GFX_RADAR_SENSOR_H

#include <vector>
#include "track.h"

class Unit;
struct GFXColor;  // Edit from class to struct as defined in gfxlib_struct.

namespace Radar
{

// Sensor is a proxy for two types of information:
//   1. The operational parameters of the radar (e.g. range)
//   2. Information detected by the radar (e.g. tracks)
class Sensor
{
public:
    typedef std::vector<Track> TrackCollection;

    struct Capability
    {
        enum Value
        {
            None = 0,
            FriendFoe = 1 << 0,
            ObjectType = 1 << 1,
            ThreatAssessment = 1 << 2
        };
    };

    struct ThreatLevel
    {
        enum Value
        {
            None, // Not attacking
            Low, // Lock
            Medium, // Capship with lock
            High // Missile
        };
    };

public:
    Sensor(Unit *player);

    Unit *GetPlayer() const;
    float GetCloseRange() const;
    float GetMaxRange() const;
    float GetMaxCone() const;
    float GetLockCone() const;
    // Does the sensor support the Identify Friend or Foe capability?
    bool UseFriendFoe() const;
    // Can the sensor distinguish ships from planets?
    bool UseObjectRecognition() const;
    // Can the sensor detect harmful ships
    bool UseThreatAssessment() const;

    Track CreateTrack(const Unit *) const;
    Track CreateTrack(const Unit *, const Vector&) const;

    // I am tracking target
    bool IsTracking(const Track&) const;
    bool InsideNebula() const;
    bool InRange(const Track&) const;

    const TrackCollection& FindTracksInRange() const;

    ThreatLevel::Value IdentifyThreat(const Track&) const;

    GFXColor GetColor(const Track&) const;

protected:
    Unit *player;
    float closeRange;
    mutable TrackCollection collection;
    bool useThreatAssessment;
};

} // namespace Radar

#endif
