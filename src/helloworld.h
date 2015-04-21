/*
 * helloworld.h
 *
 *  Created on: 19/04/2015
 *      Author: Francisco D. Kurpiel
 */

#ifndef SRC_HELLOWORLD_H_
#define SRC_HELLOWORLD_H_

#include <gtkmm.h>

class ExampleWindow: public Gtk::Window
{
public:
	ExampleWindow();
	virtual ~ExampleWindow();

protected:
	/* Signal handlers: */
	void on_notebook_switch_page(Gtk::Widget* page,
		guint page_num);

	// Things on the window
	Gtk::Box _win_box;
	Gtk::Notebook _notebook;

	// First TAB: Image Database
	Gtk::Box _imgdb_box;
	Gtk::Label _imgdb_label_1;
	Gtk::Label _imgdb_label_2;

	// Second TAB: Image Partition Selection
	Gtk::Label _imgpart_label;

	// Third TAB: Training
	Gtk::Label _train_label;

	// Forth TAB: Training Results
	Gtk::Label _trainresult_label;

	// Fifth TAG: Testing
	Gtk::Label _testing_label;
};

#endif /* SRC_HELLOWORLD_H_ */
