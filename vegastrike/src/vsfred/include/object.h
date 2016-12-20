#ifndef OBJECT_H
#define OBJECT_H


class object
{
	public:
	void create_object();
	void set_location(double loc_X, double loc_Y, double loc_Z);
	void set_rotation(double rot_X, double rot_Y, double rot_Z);
	void set_scale(double sca_X, double sca_Y, double sca_Z);
	void get_location();
	void get_rotation();
	void get_scale();
};

void create_object();
void set_location(double loc_X, double loc_Y, double loc_Z);
void set_rotation(double rot_X, double rot_Y, double rot_Z);
void set_scale(double sca_X, double sca_Y, double sca_Z);
void get_location();
void get_rotation();
void get_scale();
#endif // OBJECT_H
