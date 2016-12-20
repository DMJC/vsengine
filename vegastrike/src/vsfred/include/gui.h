#ifndef GUI_H
#define GUI_H
#include "display.h"

class gui
{
	public:
	Glib::RefPtr<Gtk::Builder> builder;
	void make_gui();
	virtual ~gui();

};

#endif // GUI_H
