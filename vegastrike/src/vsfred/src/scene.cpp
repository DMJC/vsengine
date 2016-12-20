#include <iostream>
#include "../include/object.h"

using namespace std;

class scene
{
	public:
		void create_scene();
};

void scene::create_scene(){
	cout << "Creating New Scene\n" << endl;

	cout << "Loading Default Scene Preferences\n" << endl;
};
