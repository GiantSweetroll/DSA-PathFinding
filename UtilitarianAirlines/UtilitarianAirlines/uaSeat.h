#pragma once

#include "wx/wx.h"
#include "uaID.h"

class uaSeat : public wxPanel
{
	//Constructor
public:
	uaSeat(wxWindow* window);
	~uaSeat();

	//Fields
private:
	wxButton* btnBack;
};

