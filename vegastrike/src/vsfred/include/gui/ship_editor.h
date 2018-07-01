#ifndef SHIP_EDITOR_H
#define SHIP_EDITOR_H

#include "../main.h"
#include "../gui.h"
#include "../ship_object.h"

class ship_editor {
	public:
		Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("vsfred.gtkbuilder");
		Gtk::Window* ship_editor_window = nullptr;

		void make_ship_editor();
		void show_ship_editor();
		void hide_ship_editor();
};

#endif //SHIP_EDITOR_H
