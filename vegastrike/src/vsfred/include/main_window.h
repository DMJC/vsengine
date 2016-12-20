class MainWindow: public Gtk::Window {
private:

public:
	/** Quit handler **/
	void
	OnQuit()
	{
		hide();
	}

	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>&builder):
        	Gtk::Window(cobject), _builder(builder)
	{

	}
	Glib::RefPtr<Gtk::Builder> _builder;
	

};
