/*
 * helloworld.cc
 *
 *  Created on: 19/04/2015
 *      Author: Francisco D. Kurpiel
 */

#include <iostream>
#include "helloworld.h"

ExampleWindow::ExampleWindow() :
	m_VBox(Gtk::ORIENTATION_VERTICAL)
{
	set_title("Gtk::Notebook example");
	set_border_width(10);
	set_default_size(400, 200);

	add (m_VBox);

	//Add the Notebook, with the button underneath:
	m_Notebook.set_border_width(10);
	m_VBox.pack_start(m_Notebook);

	//Add the Notebook pages:
	m_Notebook.append_page(m_LabelSourceImages, "Image Selection");
	m_Notebook.append_page(m_LabelPartitionSelection, "Selection Partition");
	m_Notebook.append_page(m_LabelTraining, "Training");
	m_Notebook.append_page(m_LabelResult, "Training Results");
	m_Notebook.append_page(m_LabelTest, "Tests");

	m_Notebook.signal_switch_page().connect(
		sigc::mem_fun(*this, &ExampleWindow::on_notebook_switch_page));

	show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_quit()
{
	hide();
}

void ExampleWindow::on_notebook_switch_page(
	Gtk::Widget* /* page */,
	guint page_num)
{
	std::cout << "Switched to tab with index " << page_num << std::endl;
}
