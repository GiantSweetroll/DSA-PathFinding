#pragma once

#include "wx/wx.h"
#include "uaID.h"
#include "uaMethods.h"

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
	void initSeating(int seatRows, int left, int right, int exits[][3]);
};

