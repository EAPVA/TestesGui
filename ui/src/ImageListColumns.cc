/*
 * ImageListColumns.cc
 *
 *  Created on: 28/04/2015
 *      Author: Francisco D. Kurpiel
 */

#include <gtkmm.h>
#include <ImageListColumns.h>

using namespace Ghog::Ui;

ImageListColumns::ImageListColumns()
{
	add (m_col_text);
	add (m_col_number);
	add (m_col_icon);
}
