#include "../include/display.h"
#include <iostream>
#include <gtkmm.h>
#include "../include/view.h"
#include "../include/gui.h"

using namespace std;

void create_display(int num_displays) {
Gtk::Grid display_grid;
Gtk::Button m_button_1, m_button_2;
//GRID within GTK Builder file is called view_grid


//gtk_container_add (GTK_CONTAINER (MainWindow:mainwindow), display); //binds the new display to the window.

	switch (num_displays){
		case 2:
			cout << "Creating one 3d View and a Top View" << endl;
			display_grid.add(m_button_1);
			display_grid.add(m_button_2);
			display_grid.attach_next_to(m_button_1, Gtk::POS_BOTTOM, 1, 1);

//			gtk_grid_attach (GTK_GRID (display_grid), view, 0, 0, 1, 1);
//			gtk_grid_attach (GTK_GRID (grid), view, 1, 0, 1, 1);
		break;
		case 3:
			cout << "Creating one 3d View, a Top and a Left View" << endl;
//			gtk_grid_attach (GTK_GRID (grid), view, 0, 0, 1, 1);
//			gtk_grid_attach (GTK_GRID (grid), view, 1, 0, 1, 1);
//			gtk_grid_attach (GTK_GRID (grid), view, 0, 1, 2, 1);
		break;
		case 4:
			cout << "Creating Four Viewports" << endl;
//			gtk_grid_attach (GTK_GRID (grid), view, 0, 0, 1, 1);
//			gtk_grid_attach (GTK_GRID (grid), view, 1, 0, 1, 1);
//			gtk_grid_attach (GTK_GRID (grid), view, 0, 1, 1, 1);			
//			gtk_grid_attach (GTK_GRID (grid), view, 1, 1, 1, 1);
		break;
		default:
			cout << "Creating one 3d View" << endl;
//			gtk_grid_attach (GTK_GRID (grid), view, 0, 0, 1, 1);
		break;
	}
};
