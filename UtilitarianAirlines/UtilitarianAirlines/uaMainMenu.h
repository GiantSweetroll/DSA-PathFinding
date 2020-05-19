#pragma once

#include "wx/wx.h"
#include "uaID.h"
#include "uaCanvas.h"

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
	wxStaticBitmap* logo = nullptr;
	wxPanel* panelTop = nullptr;
	wxPanel* panelBelow = nullptr;
	wxPanel* panelCenter = nullptr;
	uaCanvas* panelBackground = nullptr;

	//Methods
private:
	void Init();
	void InitPanelTop();
	void InitPanelBelow();
	void InitPanelCenter();
};

