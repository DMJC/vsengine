#include "../include/mission.h"

void mission::create_mission()
{
	
}

void mission::add_ship_to_mission(ship_object new_ship)
{
	this -> ships.push_front(new_ship);
}

void mission::add_wing_to_mission(wing_object new_wing)
{
	this -> wings.push_front(new_wing);
}

void mission::add_asteroid_field_to_mission()
{
	
}

void mission::set_mission_name(string mission_name)
{
	this -> name = mission_name;
}

void mission::set_mission_description(string mission_description)
{
	this -> description = mission_description;
}

void mission::set_mission_notes(string mission_notes)
{
	this -> notes = mission_notes;
}

void mission::set_mission_designer(string mission_designer)
{
	this -> designer = mission_designer;
}