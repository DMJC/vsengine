#ifndef SCENE_H
#define SCENE_H
#include "../include/object.h"
#include "../include/mission.h"
#include "../include/ship_object.h"
#include "../include/wing_object.h"
#include "../include/groups.h"

using namespace std;

class scene
{
	list <ship_object> ships;
	list <wing_object> wings;
	list <group> groups;
	
	int movement_speed;
	int rotation_speed;
    public:
        void create_scene();
		void add_ship_to_scene();
		void add_wing_to_scene();
		void add_asteroid_field_to_scene();
		void set_movement_speed(int movement_speed);
		void set_rotation_speed(int rotation_speed);
		void set_group(int group_num);
		void select_group(int group_number);

	protected:
    private:
};

void create_scene();
#endif // SCENE_H

