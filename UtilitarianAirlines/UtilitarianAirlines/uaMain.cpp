#include "uaMain.h"

uaMain::uaMain() : wxFrame(nullptr, wxID_ANY, "Seating - Utilitarian Airlines", wxPoint(50, 50), wxSize(800, 600))
{
	//Initialization
	mainMenu = new uaMainMenu(this);
	wxGridSizer* grid = new wxGridSizer(1, 3, 0, 0);
;	//panelReg = new wxPanel(this, 10002, wxPoint(0,0), wxSize(c_wWidth, c_wHeight));

	//Properties
	mainMenu->SetBackgroundColour(wxColour(135, 223, 154, 0));

	//Add to sizer
	grid->Add(1, 1);
	grid->Add(mainMenu, wxSizerFlags().Expand());
	grid->Add(1, 1);
	
	this->SetSizer(grid);
	this->Layout();
}

uaMain::~uaMain()
{

}

/*
void uaMain::InitMainMenu()
{
	//Initialization
	panelMain = new wxPanel(this, 10001, wxPoint(0, 0), wxSize(300, 200));
	wxGridSizer* grid = new wxGridSizer(2, 1, 0, 0);
	btnMainReg = new wxButton(panelMain, wxID_ANY, "Register");
	btnMainSeat = new wxButton(panelMain, wxID_ANY, "See Seating");
	btnMainExit = new wxButton(panelMain, wxID_ANY, "Exit");
	wxPanel* top = new wxPanel(panelMain, wxID_ANY);
	wxGridSizer* gridTop = new wxGridSizer(1, 1, 0, 0);
	wxPanel* below = new wxPanel(panelMain, wxID_ANY);
	wxGridSizer* gridBelow = new wxGridSizer(3, 1, 0, 0);
	wxButton* dummy = new wxButton(panelMain, wxID_ANY, "For Logo");

	//Properties
	gridTop->Add(dummy, wxSizerFlags().Expand());
	top->SetSizer(gridTop);
	top->Layout();
	gridBelow->Add(btnMainReg, wxSizerFlags().Centre());
	gridBelow->Add(btnMainSeat, wxSizerFlags().Centre());
	gridBelow->Add(btnMainExit, wxSizerFlags().Centre());
	below->SetSizer(gridBelow);
	below->Layout();
	grid->Add(top, wxSizerFlags().Expand());
	grid->Add(below, wxSizerFlags().Expand());

	panelMain->SetSizer(grid);
	panelMain->Layout();
}*/