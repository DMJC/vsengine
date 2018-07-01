#ifndef GROUPS_H
#define GROUPS_H
#include "ship_object.h"

class group{
	public:
		int number;
		list <ship_object> ships;
		void add_to_group(ship_object add_ship);
		void del_from_group(ship_object del_ship);
	protected:
	private:
};

#endif //GROUPS_H