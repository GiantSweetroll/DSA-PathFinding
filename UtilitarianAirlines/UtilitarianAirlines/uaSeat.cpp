#include "uaSeat.h"

using namespace std;

extern BetterPlane plane1;

uaSeat::uaSeat(wxWindow* parent, BetterPlane plane, string email) : wxPanel(parent, wxID_ANY)
{
	banner = new wxStaticBitmap(this, wxID_ANY, wxBitmap("banner_Seat.bmp", wxBITMAP_TYPE_BMP));
	panelSeating = uaMethods::initBasicPanelSeat(this, false, plane, email);
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* marginsLR = new wxBoxSizer(wxHORIZONTAL);

	//Properties
	this->SetBackgroundColour(*wxWHITE);

	//Add to sizer
	marginsLR->AddSpacer(50);
	mainSizer->Add(banner);
	mainSizer->AddSpacer(15);
	mainSizer->Add(panelSeating, wxSizerFlags().Expand());
	mainSizer->AddSpacer(30);
	marginsLR->Add(mainSizer);
	marginsLR->AddSpacer(50);

	panelSeating->Show();
	this->SetSizer(marginsLR);
	this->Layout();
}

uaSeat::~uaSeat()
{

}