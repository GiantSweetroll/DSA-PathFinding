#pragma once

#include "wx/wx.h"
#include "uaID.h"
#include "uaMethods.h"
#include "uaConstants.h"

class uaSeat : public wxPanel
{
	//Constructor
public:
	uaSeat(wxWindow* window);
	~uaSeat();

	//Fields
private:
	wxButton* btnBack;
	wxPanel* panelSeating;

	//Methods
private:
	void initSeating(int seatRows, int left, int middle, int right, int exits[][3]);
};

