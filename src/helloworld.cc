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
	_imgdb_col1(Gtk::ORIENTATION_VERTICAL),
	_imgdb_col2(Gtk::ORIENTATION_VERTICAL),
	_imgdb_col3(Gtk::ORIENTATION_VERTICAL),
	_imgdb_col4(Gtk::ORIENTATION_VERTICAL),
	_imgdb_label_1("Lista Completa"),
	_imgdb_label_2("L2"),
	_imgdb_label_3("L3"),
	_imgdb_label_4("L4")
{
	set_title("Gtk::Notebook example");
	set_border_width(10);
	set_default_size(400, 200);

	add (_win_box);

	// Add the Notebook, with the button underneath:
	_notebook.set_border_width(10);
	_win_box.pack_start(_notebook);

	// Notebook Page 1: ImageDatabase
	_imgdb_liststore = Gtk::ListStore::create(_imgdb_col);
	Gtk::TreeModel::Row row = *_imgdb_liststore->append();
	row[_imgdb_col.m_col_number] = 1234;
	row[_imgdb_col.m_col_text] = "Someothertext";
	_imgdb_tv.set_model(_imgdb_liststore);
	_imgdb_tv.append_column("id", _imgdb_col.m_col_number);
	_imgdb_tv.append_column("text", _imgdb_col.m_col_text);

	_imgdb_col1.set_border_width(5);
	_imgdb_col1.pack_start(_imgdb_label_1, Gtk::PACK_SHRINK);
	_imgdb_col1.pack_start(_imgdb_tv);
	_imgdb_box.pack_start(_imgdb_col1);

	_imgdb_box.pack_start(_imgdb_label_2);
	_imgdb_box.pack_start(_imgdb_label_3);
	_imgdb_box.pack_start(_imgdb_label_4);
	_notebook.append_page(_imgdb_box, "Image Database");

	// Notebook Page 2: Image Partition Selection
	_notebook.append_page(_imgpart_label, "Selection Partition");

	// Notebook Page 3: Training
	_notebook.append_page(_train_label, "Training");

	// Notebook Page 4: Training Result
	_notebook.append_page(_trainresult_label, "Training Results");

	// Notebook Page 5: Tests
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
