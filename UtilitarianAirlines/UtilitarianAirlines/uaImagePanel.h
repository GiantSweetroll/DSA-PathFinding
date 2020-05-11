#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

class uaImagePanel : public wxPanel
{
	//Constructor
public:
	uaImagePanel(wxFrame* parent, wxString file, wxBitmapType format);

	//Fields
private:
	wxBitmap image;

	//Methods
public:
	void paintEvent(wxPaintEvent& evt);
	void paintNow();

	void render(wxDC& dc);

	DECLARE_EVENT_TABLE()
};

