#ifndef PREFERENCES_H
#define PREFERENCES_H
#include <gtkmm.h>

using namespace std;

class preferences
{
    public:
	void load_preferences(string filename);
//        ~load_preferences();
	int interface_type;

    private:
};

void load_preferences(string filename);
#endif // PREFERENCES_H
