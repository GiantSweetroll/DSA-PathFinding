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
	panelBackground = new uaCanvas(this, wxBitmap("background.bmp", wxBITMAP_TYPE_BMP));
	this->InitPanelCenter();
	wxGridSizer* grid = new wxGridSizer(1, 1, 0, 0);
	wxGridSizer* innerGrid = new wxGridSizer(1, 3, 0, 0);
	
	//add to sizer
	innerGrid->Add(1, 1);
	innerGrid->Add(panelCenter, wxSizerFlags().Expand());
	innerGrid->Add(1, 1);
	grid->Add(panelBackground, wxSizerFlags().Expand());

	panelBackground->SetSizer(innerGrid);
	panelBackground->Layout();

	this->SetSizer(grid);
	this->Layout();
}

void uaMainMenu::InitPanelCenter()
{
	//Initialization
	panelCenter = new wxPanel(panelBackground, wxID_ANY);
	this->InitPanelTop();
	this->InitPanelBelow();
	wxGridSizer* grid = new wxGridSizer(2, 1, 0, 0);

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
	logo = new wxStaticBitmap(panelTop, wxID_ANY, wxBitmap("logo.bmp", wxBITMAP_TYPE_BMP));
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
	btnReg = new wxButton(panelBelow, uaID::c_btnMainReg, " Register ");
	btnSeat = new wxButton(panelBelow, uaID::c_btnMainSeat, "View Seat");
	btnExit = new wxButton(panelBelow, uaID::c_btnMainExit, "     Exit     ");
	wxGridSizer* grid = new wxGridSizer(3, 1, 0, 0);
	wxFont basicFont(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxColour basicColor(27, 167, 182, 255);

	//Properties
	btnReg->SetFont(basicFont);
	btnReg->SetBackgroundColour(basicColor);
	btnReg->SetForegroundColour(wxColour(255, 255, 255, 255));
	btnSeat->SetFont(basicFont);
	btnSeat->SetBackgroundColour(basicColor);
	btnSeat->SetForegroundColour(wxColour(255, 255, 255, 255));
	btnExit->SetFont(basicFont);
	btnExit->SetBackgroundColour(basicColor);
	btnExit->SetForegroundColour(wxColour(255, 255, 255, 255));

	//Add to sizer
	grid->Add(btnReg, wxSizerFlags().Centre());
	grid->Add(btnSeat, wxSizerFlags().Centre());
	grid->Add(btnExit, wxSizerFlags().Centre());

	//Set panel sizer
	panelBelow->SetSizer(grid);

	panelBelow->Layout();
}