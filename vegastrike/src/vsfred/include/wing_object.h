
#ifndef WING_OBJECT_H
#define WING_OBJECT_H
#include "ship_object.h"
#include <string>
#include <list>

class wing_object{
	std::string name;
	std::list<ship_object> ships;
	
	public:
		void add_ship_to_wing(ship_object add_ship);
		void delete_ship_from_wing(ship_object remove_ship);
};

#endif //WING_OBJECT_H