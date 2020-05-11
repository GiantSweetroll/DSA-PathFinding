#include "uaMainMenu.h"

uaMainMenu::uaMainMenu(wxWindow* parent) : wxPanel(parent, 10001)
{
	this->Init();
}

uaMainMenu::~uaMainMenu()
{

}

void uaMainMenu::Init()
{
	//Initialization
	this->InitPanelTop();
	this->InitPanelBelow();
	wxGridSizer* grid = new wxGridSizer(2, 1, 0, 0);

	//Add to sizer
	grid->Add(panelTop, wxSizerFlags().Expand());
	grid->Add(panelBelow, wxSizerFlags().Expand());

	this->SetSizer(grid);
	this->Layout();
}

void uaMainMenu::InitPanelTop()
{
	//Initialization
	panelTop = new wxPanel(this, wxID_ANY);
	btnLogo = new wxButton(panelTop, wxID_ANY, "Logo goes here");
	wxGridSizer* grid = new wxGridSizer(1, 1, 0, 0);

	//Add to sizer
	grid->Add(btnLogo, wxSizerFlags().Expand());

	//Set panel sizer
	panelTop->SetSizer(grid);

	panelTop->Layout();
}

void uaMainMenu::InitPanelBelow()
{
	//Initialization
	panelBelow = new wxPanel(this, wxID_ANY);
	btnReg = new wxButton(panelBelow, wxID_ANY, "Register");
	btnSeat = new wxButton(panelBelow, wxID_ANY, "See Seating");
	btnExit = new wxButton(panelBelow, wxID_ANY, "Exit");
	wxGridSizer* grid = new wxGridSizer(3, 1, 0, 0);

	//Add to sizer
	grid->Add(btnReg, wxSizerFlags().Centre());
	grid->Add(btnSeat, wxSizerFlags().Centre());
	grid->Add(btnExit, wxSizerFlags().Centre());

	//Set panel sizer
	panelBelow->SetSizer(grid);

	panelBelow->Layout();
}