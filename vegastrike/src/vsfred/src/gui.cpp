#include "../include/gui.h"
#include "../include/ship_editor.h"
#include "../../gldrv/winsys.h"

void unitparse(Gtk::ComboBoxText *text/*, string filename*/){
	cout << "opening Units.csv" << endl;
	ifstream infile;
	infile.open("units.csv", ifstream::in);

	cout << "reading Units.csv" << endl;
//add check that we haven't hit weapons.
/*for ( type == FIGHTER|BOMBER|INTERCEPTOR|SHUTTLE){
}*/
/*	while (!infile.eof()) {
		string str;
		infile.ignore(1, '"');
		getline( infile, &str, '"' );
		infile.ignore(numeric_limits<streamsize>::max(), '\n');
//		cout << str << endl;
		text->append(str.c_str());
		cout << "WTF" << endl;
	}
	cout << "Closing Up" << endl;*/
	infile.close();
}

void show_window_clicked(Gtk::Widget *widget)
{
	cout << "showing window" << endl;
	widget->show();
}

void hide_window_clicked(Gtk::Widget *widget)
{
	cout << "hiding window" << endl;
	widget->hide();
}

void on_quit_clicked(void)
{
	cout << "Quitting" << endl;
	gtk_main_quit();
}

int gtkFloatExposeEvent (GtkWidget *widget, GdkEventExpose *event, gpointer data)
	{
	gdk_window_clear_area (widget, event->area.x, event->area.y, event->area.width, event->area.height);
	gdk_gc_set_clip_rectangle (widget->style->fg_gc[widget->state], &event->area);
	gdk_draw_rgb_32_image(widget->window, widget->style->fg_gc[widget->state],0,0,image->w, image->h,
	GDK_RGB_DITHER_NORMAL,image->pixels,image->pitch);
	gdk_gc_set_clip_rectangle (widget->style->fg_gc[widget->state],NULL);

	cairo_t *cr = gdk_cairo_create (window);
	gdk_cairo_set_source_pixbuf (cr, pixbuf, x, y);
	cairo_paint (cr);
	cairo_destroy (cr);
	return 1;
}

void gui::make_gui()
{
	cout << "Opening Glade File: " << endl;
	auto app = Gtk::Application::create("VSFRED");

	Glib::RefPtr<Gtk::Builder> builder = 	Gtk::Builder::create_from_file("vsfred.gtkbuilder");

	cout << "File opened, now testing contents: " << endl;

	Gtk::Window* main_window = nullptr;
	Gtk::Window* ship_editor_window = nullptr;
	Gtk::Window* wing_editor_window = nullptr;
	Gtk::Window* about_window = nullptr;
	Gtk::MenuItem* help_about_menuitem = nullptr;
	Gtk::MenuItem* ship_editor_menuitem = nullptr;
	Gtk::MenuItem* wing_editor_menuitem = nullptr;
	Gtk::MenuItem* file_quit_menuitem = nullptr;
	Gtk::MenuItem* file_open_menuitem = nullptr;
	Gtk::MenuItem* file_save_menuitem = nullptr;
	Gtk::MenuItem* file_saveas_menuitem = nullptr;
	Gtk::Grid* view_grid = nullptr;
	Gtk::ComboBoxText* ship_type_combobox = nullptr;

	builder->get_widget("main_window", main_window);
	builder->get_widget("ship_editor_window", ship_editor_window);
	builder->get_widget("wing_editor_window", wing_editor_window);
	builder->get_widget("about_window", about_window);
	builder->get_widget("main_view_grid", view_grid);
	builder->get_widget("help_about_menuitem", help_about_menuitem);
	builder->get_widget("file_quit_menuitem", file_quit_menuitem);
	builder->get_widget("ship_editor_menuitem", ship_editor_menuitem);
	builder->get_widget("ship_type_combobox", ship_type_combobox);
	builder->get_widget("wing_editor_menuitem", wing_editor_menuitem);


	unitparse(ship_type_combobox);
	cout << "completed parse" << endl;

/*	Gtk::GLArea view;
	view.set_hexpand();
	view.set_vexpand();
	view_grid->add(view);*/
	g_signal_connect (G_OBJECT (view_grid), "expose_event", G_SIGNAL_FUNC(gtkFloatExposeEvent), (void *)source->image); 
	cout << "Display Added to Grid" << endl;

	//Activates a void function(arg); with one arg.
	help_about_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (about_window) ) );
	ship_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (ship_editor_window) ) );
	wing_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (wing_editor_window) ) );
	//Activates a void function(void);
	file_quit_menuitem->signal_activate().connect(sigc::ptr_fun(on_quit_clicked));

	main_window->show();
	view_grid->show();
	view.show();

	app->run(*main_window);
}


gui::~gui()
{
	gtk_main_quit();
}
