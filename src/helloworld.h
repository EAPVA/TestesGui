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

	/* Child widgets: */
	Gtk::Box m_VBox;
	Gtk::Notebook m_Notebook;

	Gtk::Label m_LabelSourceImages;
	Gtk::Label m_LabelPartitionSelection;
	Gtk::Label m_LabelTraining;
	Gtk::Label m_LabelResult;
	Gtk::Label m_LabelTest;
};

#endif /* SRC_HELLOWORLD_H_ */
