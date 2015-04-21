/*
 * main.cpp
 *
 *  Created on: 17/04/2015
 *      Author: Francisco D. Kurpiel
 */

#include <gtkmm.h>

#include "helloworld.h"
#include <gtkmm/application.h>

int main(
	int argc,
	char *argv[])
{
	Glib::RefPtr < Gtk::Application > app = Gtk::Application::create(argc, argv,
		"org.gtkmm.example");

	ExampleWindow ew;

	return app->run(ew);
}
