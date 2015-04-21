/*
 * helloworld.cc
 *
 *  Created on: 19/04/2015
 *      Author: Francisco D. Kurpiel
 */

#include <iostream>
#include "helloworld.h"

ExampleWindow::ExampleWindow() :
	_win_box(Gtk::ORIENTATION_VERTICAL),
	_imgdb_box(Gtk::ORIENTATION_HORIZONTAL),
	_imgdb_label_1("Yay!!!"),
	_imgdb_label_2("Yoy!!!")
{
	set_title("Gtk::Notebook example");
	set_border_width(10);
	set_default_size(400, 200);

	add (_win_box);

	//Add the Notebook, with the button underneath:
	_notebook.set_border_width(10);
	_win_box.pack_start(_notebook);

	//Add the Notebook pages:
	_imgdb_box.pack_start(_imgdb_label_1);
	_imgdb_box.pack_start(_imgdb_label_2);
	_notebook.append_page(_imgdb_box, "Image Selection");

	_notebook.append_page(_imgpart_label, "Selection Partition");
	_notebook.append_page(_train_label, "Training");
	_notebook.append_page(_trainresult_label, "Training Results");
	_notebook.append_page(_testing_label, "Tests");

	_notebook.signal_switch_page().connect(
		sigc::mem_fun(*this, &ExampleWindow::on_notebook_switch_page));

	show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_notebook_switch_page(Gtk::Widget* /* page */,
	guint page_num)
{
	std::cout << "Switched to tab with index " << page_num << std::endl;
}
