// -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef VEGASTRIKE_CMD_AI_AUTODOCKING_H
#define VEGASTRIKE_CMD_AI_AUTODOCKING_H

#include <deque>
#include <boost/shared_ptr.hpp>
#include "cmd/ai/order.h"

class Unit;
class QVector;

namespace Orders
{

// Navigate the player to the closest auto-dockable port.
//
// If the station is too far away, the normal auto pilot will move the player
// to the station.
//
// An auto-dockable port may have a row of waypoints associated with it. This
// order will face and move towards the first waypoint. When this is reached,
// it will face and move towards the next waypoint, and so on until the docking
// port is reached.
//
// When the docking port is reached the player is docked at the station.
//
// Pre-condition:
//  o A station has been selected.
//  o Docking clearance has been obtained.
//  o The station has at least one docking port that is auto-dockable, available,
//    and big enough to fit the player.
//  o The nearest available docking port must be in line-of-sight.
//
// Post-condition:
//  o One of
//    - The player has been docked.
//    - No suitable docking port is available.
//    - The player or the station has been destroyed.
//
// Limitations:
//  o The player moves directly towards the first waypoint. If the station is
//    between the player and the waypoint, the player will collide with the
//    station.
//  o If auto-docking is disengaged after travelling through a couple of
//    waypoints and then re-engaged, then the player will start by moving directly
//    towards the first waypoint.
//  o The player cannot auto-dock on capital ships. It cannot handle moving
//    stations, and it does not request clearance at fixed intervals to prevent
//    the capital ship from moving away.
//  o Cannot dock capital ships. A capital ship must align one of its docking
//    ports with one of the station's docking ports to dock, and this order does
//    not do that.

class AutoDocking : public Order
{
    typedef void (AutoDocking::*StateFunction)(Unit *, Unit *);

public:
    typedef std::deque<int> DockingPath;

    AutoDocking(Unit *destination);

    void Execute();

    static bool CanDock(Unit *player, Unit *station);

protected:
    // States
    void InitialState(Unit *player, Unit *station);
    void SelectionState(Unit *, Unit *);
    void ApproachState(Unit *, Unit *);
    void DockingState(Unit *, Unit *);
    void DockedState(Unit *, Unit *);
    void UndockingState(Unit *, Unit *);
    void DepartureState(Unit *, Unit *);
    void AbortState(Unit *, Unit *);
    void EndState(Unit *, Unit *);

    void EnqueuePort(Unit *, Unit *, size_t);
    void EraseOrders();

private:
    StateFunction state;
    UnitContainer target;
    // waypoints followed by docking port (back)
    DockingPath dockingPath;
};

} // namespace Orders

#endif
