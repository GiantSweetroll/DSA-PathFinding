#pragma once

#include "wx/wx.h"
#include "uaMainMenu.h"
#include "uaReg.h"

class uaMain : public wxFrame
{
	//Constructors
public:
	uaMain();
	~uaMain();

	//Fields
public:
	const int c_wWidth = 800;
	const int c_wHeight = 600;
private:
	uaMainMenu* mainMenu = nullptr;		//Main Menu
	uaReg* reg = nullptr;				//Registration Menu
	wxGridSizer* sizer = nullptr;

	//Methods
	void OnRegClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

