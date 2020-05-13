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
	this->InitPanelCenter();
	wxGridSizer* grid = new wxGridSizer(1, 3, 0, 0);
	
	//add to sizer
	grid->Add(1, 1);
	grid->Add(panelCenter, wxSizerFlags().Expand());
	grid->Add(1, 1);

	this->SetSizer(grid);
	this->Layout();
}

void uaMainMenu::InitPanelCenter()
{
	//Initialization
	panelCenter = new wxPanel(this, wxID_ANY);
	this->InitPanelTop();
	this->InitPanelBelow();
	wxGridSizer* grid = new wxGridSizer(2, 1, 0, 0);

	//Properties
	panelCenter->SetBackgroundColour(wxColour(135, 223, 154, 0));

	//Add to sizer
	grid->Add(panelTop, wxSizerFlags().Expand());
	grid->Add(panelBelow, wxSizerFlags().Expand());

	panelCenter->SetSizer(grid);
	panelCenter->Layout();
}

void uaMainMenu::InitPanelTop()
{
	//Initialization
	panelTop = new wxPanel(panelCenter, wxID_ANY);
	logo = new wxStaticBitmap(panelTop, wxID_ANY, wxBitmap("download.bmp", wxBITMAP_TYPE_BMP));
	wxGridSizer* grid = new wxGridSizer(1, 1, 0, 0);

	//Add to sizer
	grid->Add(logo, wxSizerFlags().Expand());

	//Set panel sizer
	panelTop->SetSizer(grid);

	panelTop->Layout();
}

void uaMainMenu::InitPanelBelow()
{
	//Initialization
	panelBelow = new wxPanel(panelCenter, wxID_ANY);
	btnReg = new wxButton(panelBelow, uaID::c_btnMainReg, "Register");
	btnSeat = new wxButton(panelBelow, uaID::c_btnMainSeat, "See Seating");
	btnExit = new wxButton(panelBelow, uaID::c_btnMainExit, "Exit");
	wxGridSizer* grid = new wxGridSizer(3, 1, 0, 0);

	//Add to sizer
	grid->Add(btnReg, wxSizerFlags().Centre());
	grid->Add(btnSeat, wxSizerFlags().Centre());
	grid->Add(btnExit, wxSizerFlags().Centre());

	//Set panel sizer
	panelBelow->SetSizer(grid);

	panelBelow->Layout();
}