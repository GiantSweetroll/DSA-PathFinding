#pragma once

#include "wx/wx.h"
#include "uaID.h"
#include "uaMethods.h"
#include "uaConstants.h"

class uaSeat : public wxPanel
{
	//Constructor
public:
	uaSeat(wxWindow* window, BetterPlane plane, string email);
	~uaSeat();

	//Fields
private:
	wxPanel* panelSeating = nullptr;
	wxStaticBitmap* banner = nullptr;
};

