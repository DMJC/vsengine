#include "../include/gui.h"
//#include "../include/ship_editor.h"
#include "../../main_loop.h"
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

void on_launch_vegastrike_clicked(void)
{
	cout << "Launching Vegastrike" << endl;
	
	system("./vegastrike");
}

void on_quit_clicked(void)
{
	cout << "Quitting" << endl;
	
	CockpitKeys::QuitNow();
}

void gui::make_gui(scene current_scene)
{
	cout << "Opening Glade File: " << endl;
	auto app = Gtk::Application::create("VSFRED");

	this -> builder = Gtk::Builder::create_from_file("vsfred.gtkbuilder");

	cout << "File opened, now testing contents: " << endl;

	Gtk::Window* file_new_window = nullptr;
	Gtk::Window* file_open_window = nullptr;
	Gtk::Window* file_save_window = nullptr;
	Gtk::Window* file_saveas_window = nullptr;

	Gtk::Window* main_window = nullptr;
	Gtk::Window* ship_editor_window = nullptr;
	Gtk::Window* wing_editor_window = nullptr;
	Gtk::Window* objects_editor_window = nullptr;
	Gtk::Window* waypoint_editor_window = nullptr;
	Gtk::Window* mission_objective_editor_window = nullptr;
	Gtk::Window* events_editor_window = nullptr;
	Gtk::Window* team_loadout_editor_window = nullptr;
	Gtk::Window* background_editor_window = nullptr;
	Gtk::Window* reinforcements_editor_window = nullptr;
	Gtk::Window* asteroid_field_editor_window = nullptr;
	Gtk::Window* minefield_editor_window = nullptr;
	Gtk::Window* mission_specs_editor_window = nullptr;
	Gtk::Window* briefing_editor_window = nullptr;
	Gtk::Window* debriefing_editor_window = nullptr;
	Gtk::Window* shield_system_editor_window = nullptr;
	Gtk::Window* command_briefing_editor_window = nullptr;
	Gtk::Window* ship_flags_editor_window = nullptr;
	Gtk::Window* voice_acting_window = nullptr;
	Gtk::Window* campaign_editor_window = nullptr;
	Gtk::Window* help_about_window = nullptr;
	Gtk::Window* specs_editor_window = nullptr;
	Gtk::Window* about_window = nullptr;

	Gtk::Window* misc_mission_stats_window = nullptr;
	Gtk::Window* misc_error_checker_window = nullptr;
	Gtk::Window* help_helptopics_window = nullptr;
	Gtk::Window* help_showsexphelp_window = nullptr;



	Gtk::MenuItem* file_new_menuitem = nullptr;
	Gtk::MenuItem* file_open_menuitem = nullptr;
	Gtk::MenuItem* file_save_menuitem = nullptr;
	Gtk::MenuItem* file_saveas_menuitem = nullptr;
	Gtk::MenuItem* file_launch_vegastrike_menuitem = nullptr;
	Gtk::MenuItem* file_quit_menuitem = nullptr;
	
	Gtk::MenuItem* edit_undo_menuitem = nullptr;
	Gtk::MenuItem* edit_delete_menuitem = nullptr;
	Gtk::MenuItem* edit_delete_wing_menuitem = nullptr;
	Gtk::MenuItem* edit_disable_undo_menuitem = nullptr;
	
	Gtk::MenuItem* movement_x1_menuitem = nullptr;
	Gtk::MenuItem* movement_x2_menuitem = nullptr;
	Gtk::MenuItem* movement_x3_menuitem = nullptr;
	Gtk::MenuItem* movement_x5_menuitem = nullptr;
	Gtk::MenuItem* movement_x8_menuitem = nullptr;
	Gtk::MenuItem* movement_x10_menuitem = nullptr;
	Gtk::MenuItem* movement_x50_menuitem = nullptr;
	Gtk::MenuItem* movement_x100_menuitem = nullptr;
	Gtk::MenuItem* rotation_x1_menuitem = nullptr;
	Gtk::MenuItem* rotation_x5_menuitem = nullptr;
	Gtk::MenuItem* rotation_x12_menuitem = nullptr;
	Gtk::MenuItem* rotation_x25_menuitem = nullptr;
	Gtk::MenuItem* rotation_x50_menuitem = nullptr;
	
	Gtk::MenuItem* ship_editor_menuitem = nullptr;
	Gtk::MenuItem* wing_editor_menuitem = nullptr;
	Gtk::MenuItem* objects_editor_menuitem = nullptr;
	Gtk::MenuItem* waypoint_editor_menuitem = nullptr;
	Gtk::MenuItem* mission_objective_editor_menuitem = nullptr;
	Gtk::MenuItem* events_editor_menuitem = nullptr;
	Gtk::MenuItem* team_loadout_editor_menuitem = nullptr;
	Gtk::MenuItem* background_editor_menuitem = nullptr;
	Gtk::MenuItem* reinforcements_editor_menuitem = nullptr;
	Gtk::MenuItem* asteroid_field_editor_menuitem = nullptr;
	Gtk::MenuItem* minefield_editor_menuitem = nullptr;
	Gtk::MenuItem* mission_specs_editor_menuitem = nullptr;
	Gtk::MenuItem* briefing_editor_menuitem = nullptr;
	Gtk::MenuItem* debriefing_editor_menuitem = nullptr;
	Gtk::MenuItem* shield_system_editor_menuitem = nullptr;
	Gtk::MenuItem* command_briefing_editor_menuitem = nullptr;
	Gtk::MenuItem* ship_flags_editor_menuitem = nullptr;
	Gtk::MenuItem* voice_acting_editor_menuitem = nullptr;
	Gtk::MenuItem* campaign_editor_menuitem = nullptr;
	
	Gtk::MenuItem* group_0_menuitem = nullptr;
	Gtk::MenuItem* group_1_menuitem = nullptr;
	Gtk::MenuItem* group_2_menuitem = nullptr;
	Gtk::MenuItem* group_3_menuitem = nullptr;
	Gtk::MenuItem* group_4_menuitem = nullptr;
	Gtk::MenuItem* group_5_menuitem = nullptr;
	Gtk::MenuItem* group_6_menuitem = nullptr;
	Gtk::MenuItem* group_7_menuitem = nullptr;
	Gtk::MenuItem* group_8_menuitem = nullptr;
	Gtk::MenuItem* group_9_menuitem = nullptr;
	Gtk::MenuItem* set_group_0_menuitem = nullptr;
	Gtk::MenuItem* set_group_1_menuitem = nullptr;
	Gtk::MenuItem* set_group_2_menuitem = nullptr;
	Gtk::MenuItem* set_group_3_menuitem = nullptr;
	Gtk::MenuItem* set_group_4_menuitem = nullptr;
	Gtk::MenuItem* set_group_5_menuitem = nullptr;
	Gtk::MenuItem* set_group_6_menuitem = nullptr;
	Gtk::MenuItem* set_group_7_menuitem = nullptr;
	Gtk::MenuItem* set_group_8_menuitem = nullptr;
	Gtk::MenuItem* set_group_9_menuitem = nullptr;
	
	Gtk::MenuItem* misc_level_object_menuitem = nullptr;
	Gtk::MenuItem* misc_align_object_menuitem = nullptr;
	Gtk::MenuItem* misc_mark_wing_menuitem = nullptr;
	Gtk::MenuItem* misc_control_object_menuitem = nullptr;
	Gtk::MenuItem* misc_next_object_menuitem = nullptr;
	Gtk::MenuItem* misc_prev_object_menuitem = nullptr;
	Gtk::MenuItem* misc_adjust_grid_menuitem = nullptr;
	Gtk::MenuItem* misc_next_subsys_menuitem = nullptr;
	Gtk::MenuItem* misc_prev_subsys_menuitem = nullptr;
	Gtk::MenuItem* misc_cancel_subsys_menuitem = nullptr;
	Gtk::MenuItem* misc_mission_stats_menuitem = nullptr;
	Gtk::MenuItem* misc_error_checker_menuitem = nullptr;
	
	Gtk::MenuItem* help_helptopics_menuitem = nullptr;
	Gtk::MenuItem* help_about_menuitem = nullptr;
	Gtk::MenuItem* help_showsexphelp_menuitem = nullptr;
	
	Gtk::Grid* view_grid = nullptr;
	Gtk::ComboBoxText* ship_type_combobox = nullptr;


	builder->get_widget("file_new_menuitem", file_new_menuitem);
	builder->get_widget("file_open_menuitem", file_open_menuitem);
	builder->get_widget("file_save_menuitem", file_save_menuitem);
	builder->get_widget("file_saveas_menuitem", file_saveas_menuitem);
	builder->get_widget("file_launch_vegastrike_menuitem", file_launch_vegastrike_menuitem);
	builder->get_widget("file_quit_menuitem", file_quit_menuitem);
	
	builder->get_widget("edit_undo_menuitem", edit_undo_menuitem);
	builder->get_widget("edit_delete_menuitem", edit_delete_menuitem);
	builder->get_widget("edit_delete_wing_menuitem", edit_delete_wing_menuitem);
	builder->get_widget("edit_disable_undo_menuitem", edit_disable_undo_menuitem);
	
	builder->get_widget("movement_x1_menuitem", movement_x1_menuitem);
	builder->get_widget("movement_x2_menuitem", movement_x2_menuitem);
	builder->get_widget("movement_x3_menuitem", movement_x3_menuitem);
	builder->get_widget("movement_x5_menuitem", movement_x5_menuitem);
	builder->get_widget("movement_x8_menuitem", movement_x8_menuitem);
	builder->get_widget("movement_x10_menuitem", movement_x10_menuitem);
	builder->get_widget("movement_x50_menuitem", movement_x50_menuitem);
	builder->get_widget("movement_x100_menuitem", movement_x100_menuitem);
	builder->get_widget("rotation_x1_menuitem", rotation_x1_menuitem);
	builder->get_widget("rotation_x5_menuitem", rotation_x5_menuitem);
	builder->get_widget("rotation_x12_menuitem", rotation_x12_menuitem);
	builder->get_widget("rotation_x25_menuitem", rotation_x25_menuitem);
	builder->get_widget("rotation_x50_menuitem", rotation_x50_menuitem);
	
	builder->get_widget("ship_editor_menuitem", ship_editor_menuitem);
	builder->get_widget("wing_editor_menuitem", wing_editor_menuitem);
	builder->get_widget("objects_editor_menuitem", objects_editor_menuitem);
	builder->get_widget("waypoint_editor_menuitem", waypoint_editor_menuitem);
	builder->get_widget("mission_objective_editor_menuitem", mission_objective_editor_menuitem);
	builder->get_widget("events_editor_menuitem", events_editor_menuitem);
	builder->get_widget("team_loadout_editor_menuitem", team_loadout_editor_menuitem);
	builder->get_widget("background_editor_menuitem", background_editor_menuitem);
	builder->get_widget("reinforcements_editor_menuitem", reinforcements_editor_menuitem);
	builder->get_widget("asteroid_field_editor_menuitem", asteroid_field_editor_menuitem);
	builder->get_widget("minefield_editor_menuitem", minefield_editor_menuitem);
	builder->get_widget("mission_specs_editor_menuitem", mission_specs_editor_menuitem);
	builder->get_widget("briefing_editor_menuitem", briefing_editor_menuitem);
	builder->get_widget("debriefing_editor_menuitem", debriefing_editor_menuitem);
	builder->get_widget("shield_system_editor_menuitem", shield_system_editor_menuitem);
	builder->get_widget("command_briefing_editor_menuitem", command_briefing_editor_menuitem);
	builder->get_widget("ship_flags_editor_menuitem", ship_flags_editor_menuitem);
	builder->get_widget("voice_acting_editor_menuitem", voice_acting_editor_menuitem);
	builder->get_widget("campaign_editor_menuitem", campaign_editor_menuitem);
	
	builder->get_widget("group_0_menuitem", group_0_menuitem);
	builder->get_widget("group_1_menuitem", group_1_menuitem);
	builder->get_widget("group_2_menuitem", group_2_menuitem);
	builder->get_widget("group_3_menuitem", group_3_menuitem);
	builder->get_widget("group_4_menuitem", group_4_menuitem);
	builder->get_widget("group_5_menuitem", group_5_menuitem);
	builder->get_widget("group_6_menuitem", group_6_menuitem);
	builder->get_widget("group_7_menuitem", group_7_menuitem);
	builder->get_widget("group_8_menuitem", group_8_menuitem);
	builder->get_widget("group_9_menuitem", group_9_menuitem);
	builder->get_widget("set_group_0_menuitem", set_group_0_menuitem);
	builder->get_widget("set_group_1_menuitem", set_group_1_menuitem);
	builder->get_widget("set_group_2_menuitem", set_group_2_menuitem);
	builder->get_widget("set_group_3_menuitem", set_group_3_menuitem);
	builder->get_widget("set_group_4_menuitem", set_group_4_menuitem);
	builder->get_widget("set_group_5_menuitem", set_group_5_menuitem);
	builder->get_widget("set_group_6_menuitem", set_group_6_menuitem);
	builder->get_widget("set_group_7_menuitem", set_group_7_menuitem);
	builder->get_widget("set_group_8_menuitem", set_group_8_menuitem);
	builder->get_widget("set_group_9_menuitem", set_group_9_menuitem);
	
	builder->get_widget("misc_level_object_menuitem", misc_level_object_menuitem);
	builder->get_widget("misc_align_object_menuitem", misc_align_object_menuitem);
	builder->get_widget("misc_mark_wing_menuitem", misc_mark_wing_menuitem);
	builder->get_widget("misc_control_object_menuitem", misc_control_object_menuitem);
	builder->get_widget("misc_next_object_menuitem", misc_next_object_menuitem);
	builder->get_widget("misc_prev_object_menuitem", misc_prev_object_menuitem);
	builder->get_widget("misc_adjust_grid_menuitem", misc_adjust_grid_menuitem);
	builder->get_widget("misc_next_subsys_menuitem", misc_next_subsys_menuitem);
	builder->get_widget("misc_prev_subsys_menuitem", misc_prev_subsys_menuitem);
	builder->get_widget("misc_cancel_subsys_menuitem", misc_cancel_subsys_menuitem);
	builder->get_widget("misc_mission_stats_menuitem", misc_mission_stats_menuitem);
	builder->get_widget("misc_error_checker_menuitem", misc_error_checker_menuitem);
	
	builder->get_widget("help_helptopics_menuitem", help_helptopics_menuitem);
	builder->get_widget("help_about_menuitem", help_about_menuitem);
	builder->get_widget("help_showsexphelp_menuitem", help_showsexphelp_menuitem);

	builder->get_widget("main_window", main_window);
	builder->get_widget("ship_editor_window", ship_editor_window);
	builder->get_widget("wing_editor_window", wing_editor_window);
	builder->get_widget("objects_editor_menuitem", objects_editor_window);
	builder->get_widget("waypoint_editor_menuitem", waypoint_editor_window);
	builder->get_widget("mission_objective_editor_menuitem", mission_objective_editor_window);
	builder->get_widget("events_editor_menuitem", events_editor_window);
	builder->get_widget("team_loadout_editor_menuitem", team_loadout_editor_window);
	builder->get_widget("background_editor_menuitem", background_editor_window);
	builder->get_widget("reinforcements_editor_menuitem", reinforcements_editor_window);
	builder->get_widget("asteroid_field_editor_menuitem", asteroid_field_editor_window);
	builder->get_widget("minefield_editor_menuitem", minefield_editor_window);
	builder->get_widget("mission_specs_editor_menuitem", mission_specs_editor_window);
	builder->get_widget("briefing_editor_menuitem", briefing_editor_window);
	builder->get_widget("debriefing_editor_menuitem", debriefing_editor_window);
	builder->get_widget("shield_system_editor_window", shield_system_editor_window);
	builder->get_widget("command_briefing_editor_window", command_briefing_editor_window);
	builder->get_widget("ship_flags_editor_window", ship_flags_editor_window);
	builder->get_widget("voice_acting_window", voice_acting_window);
	builder->get_widget("about_window", help_about_window);
	builder->get_widget("main_view_grid", view_grid);
	builder->get_widget("ship_type_combobox", ship_type_combobox);

	unitparse(ship_type_combobox);
	cout << "completed parse" << endl;

	Gtk::GLArea view;
	view.set_hexpand();
	view.set_vexpand();
	view_grid->add(view);
	cout << "Display Added to Grid" << endl;
	
	ship_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (ship_editor_window) ) );
	wing_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (wing_editor_window) ) );

	file_new_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (file_new_window) ) );
	file_open_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (file_open_window) ) );
	file_save_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (file_save_window) ) );
	file_saveas_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (file_saveas_window) ) );
	file_launch_vegastrike_menuitem->signal_activate().connect(sigc::ptr_fun(on_launch_vegastrike_clicked) );
	file_quit_menuitem->signal_activate().connect(sigc::ptr_fun(on_quit_clicked) );
	
/*	edit_undo_menuitem->signal_activate().connect(sigc::mem_fun(current_scene, &scene::edit_undo) );
	edit_delete_menuitem->signal_activate().connect(sigc::mem_fun(current_scene, &scene::edit_delete) );
	edit_delete_wing_menuitem->signal_activate().connect(sigc::mem_fun(current_scene, &scene::edit_delete_wing) );
	edit_disable_undo_menuitem->signal_activate().connect(sigc::mem_fun(current_scene, &scene::edit_disable_undo) );*/
		
	movement_x1_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (1) ) );
	movement_x2_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (2) ) );
	movement_x3_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (3) ) );
	movement_x5_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (5) ) );
	movement_x8_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (8) ) );
	movement_x10_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (10) ) );
	movement_x50_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (50) ) );
	movement_x100_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_movement_speed), (100) ) );
	rotation_x1_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_rotation_speed), (1) ) );
	rotation_x5_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_rotation_speed), (5) ) );
	rotation_x12_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_rotation_speed), (12) ) );
	rotation_x25_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_rotation_speed), (25) ) );
	rotation_x50_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_rotation_speed), (50) ) );
	
	ship_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (ship_editor_window) ) );
	wing_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (wing_editor_window) ) );
	objects_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (objects_editor_window) ) );
	waypoint_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (waypoint_editor_window) ) );
	mission_objective_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (mission_objective_editor_window) ) );
	events_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (events_editor_window) ) );
	team_loadout_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (team_loadout_editor_window) ) );
	background_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (background_editor_window) ) );
	reinforcements_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (reinforcements_editor_window) ) );
	asteroid_field_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (asteroid_field_editor_window) ) );
	minefield_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (minefield_editor_window) ) );
	mission_specs_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (mission_specs_editor_window) ) );
	briefing_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (briefing_editor_window) ) );
	debriefing_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (debriefing_editor_window) ) );
	shield_system_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (shield_system_editor_window) ) );
	command_briefing_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (command_briefing_editor_window) ) );
	ship_flags_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (ship_flags_editor_window) ) );
	voice_acting_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (voice_acting_window) ) );
	campaign_editor_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (campaign_editor_window) ) );
	
	group_0_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (0) ) );
	group_1_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (1) ) );
	group_2_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (2) ) );
	group_3_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (3) ) );
	group_4_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (4) ) );
	group_5_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (5) ) );
	group_6_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (6) ) );
	group_7_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (7) ) );
	group_8_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (8) ) );
	group_9_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::select_group), (9) ) );
	
	set_group_0_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (0) ) );
	set_group_1_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (1) ) );
	set_group_2_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (2) ) );
	set_group_3_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (3) ) );
	set_group_4_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (4) ) );
	set_group_5_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (5) ) );
	set_group_6_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (6) ) );
	set_group_7_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (7) ) );
	set_group_8_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (8) ) );
	set_group_9_menuitem->signal_activate().connect(sigc::bind( sigc::mem_fun(current_scene, &scene::set_group), (9) ) );
	
/*	misc_level_object_menuitem->signal_activate().connect(sigc::ptr_fun(misc_level_object) );
	misc_align_object_menuitem->signal_activate().connect(sigc::ptr_fun(misc_align_object) );
	misc_mark_wing_menuitem->signal_activate().connect(sigc::ptr_fun(misc_mark_wing) );
	misc_control_object_menuitem->signal_activate().connect(sigc::ptr_fun(misc_control_object) );
	misc_next_object_menuitem->signal_activate().connect(sigc::ptr_fun(misc_next_object) );
	misc_prev_object_menuitem->signal_activate().connect(sigc::ptr_fun(misc_prev_object) );
	misc_prev_subsys_menuitem->signal_activate().connect(sigc::ptr_fun(misc_prev_subsys) ) );
	misc_cancel_subsys_menuitem->signal_activate().connect(sigc::ptr_fun(misc_cancel_subsys) ) );*/
	misc_mission_stats_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (misc_mission_stats_window) ) );
	misc_error_checker_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (misc_error_checker_window) ) );
	
	help_helptopics_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (help_helptopics_window) ) );
	help_about_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (help_about_window) ) );
	help_showsexphelp_menuitem->signal_activate().connect(sigc::bind( sigc::ptr_fun(show_window_clicked), (help_showsexphelp_window) ) );
		
	main_window->show();
	view_grid->show();
	view.show();

	app->run(*main_window);
}


gui::~gui()
{
	gtk_main_quit();
	CockpitKeys::QuitNow();
}
