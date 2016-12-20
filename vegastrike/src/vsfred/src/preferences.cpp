#include <iostream>
#include <fstream>

using namespace std;

class preferences
{
public:
	void load_preferences(string filename);
	int interface_type;
};

void preferences::load_preferences(string filename)
{
string line;
ifstream pref_file (filename);
int interface_type = 0;
  if (pref_file.is_open())
  {
	
    pref_file.close();
  }
cout << "Loaded Preferences\n" << endl;

};
