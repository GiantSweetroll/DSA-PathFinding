#include "uaMain.h"

wxBEGIN_EVENT_TABLE(uaMain, wxFrame)
	EVT_BUTTON(uaID::c_btnMainReg, OnMainRegClicked)
	EVT_BUTTON(uaID::c_btnMainSeat, OnMainSeatClicked)
	EVT_BUTTON(uaID::c_btnMainExit, OnMainExitClicked)
	EVT_BUTTON(uaID::c_btnRegBack, OnRegBackClicked)
wxEND_EVENT_TABLE()


uaMain::uaMain() : wxFrame(nullptr, wxID_ANY, "Seating - Utilitarian Airlines", wxPoint(0, 0), wxSize(1920, 1080))
{
	//Initialization
	mainMenu = new uaMainMenu(this);
	reg = new uaReg(this);
	sizer = new wxGridSizer(1, 1, 0, 0);
;	//panelReg = new wxPanel(this, 10002, wxPoint(0,0), wxSize(c_wWidth, c_wHeight));
	
	//Add to sizer
	sizer->Add(mainMenu, wxSizerFlags().Expand());

	this->SetSizer(sizer);
	this->Layout();
}

uaMain::~uaMain()
{

}

void uaMain::OnMainRegClicked(wxCommandEvent& evt)
{
	sizer->Replace(mainMenu, reg);
	mainMenu->Hide();
	reg->Show();

	this->Layout();
}

void uaMain::OnRegBackClicked(wxCommandEvent& evt)
{
	sizer->Replace(reg, mainMenu);
	reg->Hide();
	mainMenu->Show();

	this->Layout();
}

void uaMain::OnMainExitClicked(wxCommandEvent& evt)
{
	Destroy();
}

void uaMain::OnMainSeatClicked(wxCommandEvent& evt)
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