#pragma once

#include "wx/wx.h"
#include "uaMainMenu.h"
#include "uaReg.h"
#include "uaID.h"
#include "uaSeat.h"

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
	uaSeat* seat = nullptr;
	wxGridSizer* sizer = nullptr;

	//Methods
	void OnMainRegClicked(wxCommandEvent& evt);
	void OnMainSeatClicked(wxCommandEvent& evt);
	void OnMainExitClicked(wxCommandEvent& evt);
	void OnRegBackClicked(wxCommandEvent& evt);
	void OnSeatMainMenuClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

