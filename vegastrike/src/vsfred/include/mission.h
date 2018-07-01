#ifndef MISSION_H
#define MISSION_H
#include "../include/object.h"
#include "../include/mission.h"
#include "../include/ship_object.h"
#include "../include/wing_object.h"

using namespace std;

class mission
{
	string name;
	string description;
	string designer;
	string notes;
	
	list <ship_object> ships;
	list <wing_object> wings;
    public:
        void create_mission();
		void add_ship_to_mission(ship_object new_ship);
		void add_wing_to_mission(wing_object new_wing);
		void add_asteroid_field_to_mission();
		void set_mission_name(string mission_name);
		void set_mission_description(string mission_description);
		void set_mission_notes(string mission_notes);
		void set_mission_designer(string mission_designer);
    protected:
    private:
};

void create_mission();
#endif // MISSION_H
