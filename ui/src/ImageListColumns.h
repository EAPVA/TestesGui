/*
 * ImageListColumns.h
 *
 *  Created on: 28/04/2015
 *      Author: Francisco D. Kurpiel
 */

#ifndef IMAGELISTCOLUMNS_H_
#define IMAGELISTCOLUMNS_H_

#include <gtkmm.h>

namespace Ghog
{
namespace Ui
{

class ImageListColumns: public Gtk::TreeModelColumnRecord
{
public:
	ImageListColumns();

	Gtk::TreeModelColumn< Glib::ustring > m_col_text;
	Gtk::TreeModelColumn< int > m_col_number;
	Gtk::TreeModelColumn< Glib::RefPtr< Gdk::Pixbuf > > m_col_icon;
};

}
}

#endif /* IMAGELISTCOLUMNS_H_ */
