#ifndef GUI_H
#define GUI_H
#include "display.h"
#include "editor_callbacks.h"
#include "scene.h"


class gui
{
	private:
	Glib::RefPtr<Gtk::Builder> builder;
	public:
	void make_gui(scene current_scene);
	virtual ~gui();

};

#endif // GUI_H
