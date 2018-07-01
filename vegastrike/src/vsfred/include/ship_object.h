#ifndef SHIP_OBJECT_H
#define SHIP_OBJECT_H

class ship_object{
	float location[3];
	float rotation[3];
	
	public:
		int* get_ship_location(void);
		int* get_ship_rotation(void);
		void set_ship_location(int X, int Y, int Z);
		void set_ship_rotation(int X, int Y, int Z);
};

#endif //SHIP_OBJECT_H