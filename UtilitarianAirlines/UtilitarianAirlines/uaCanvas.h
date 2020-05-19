#pragma once

#include "wx/custombgwin.h"
#include "wx/wx.h"

class uaCanvas: public wxCustomBackgroundWindow<wxPanel>
{
public:
	uaCanvas(wxWindow* parent, wxBitmap bitmap);
	~uaCanvas();
};

