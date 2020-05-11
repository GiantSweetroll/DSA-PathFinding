#pragma once

#include "wx/wx.h"

class uaMainMenu : public wxPanel
{
	//Constructor
public:
	uaMainMenu(wxWindow* parent);
	~uaMainMenu();

	//Fields
private:
	wxButton* btnReg = nullptr;
	wxButton* btnSeat = nullptr;
	wxButton* btnExit = nullptr;
	wxButton* btnLogo = nullptr;	//Will be replaced later with a better class
	wxPanel* panelTop = nullptr;
	wxPanel* panelBelow = nullptr;

	//Methods
private:
	void Init();
	void InitPanelTop();
	void InitPanelBelow();

public:
	void revalidate();
};

