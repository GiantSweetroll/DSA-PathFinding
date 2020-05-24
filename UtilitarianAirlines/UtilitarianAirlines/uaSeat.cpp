#include "uaSeat.h"

using namespace std;

uaSeat::uaSeat(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	btnBack = new wxButton(this, uaID::c_btnSeatBack, "Back");
}

uaSeat::~uaSeat()
{

}

void uaSeat::initSeating(int seatRows, int left, int middle, int right, int exits[][3])
{
	//Note: exits[][rowNumber, amount, pos(0=left, 1=right)]

	//Initialization
	extern BetterPlane plane1;
	panelSeating = new wxPanel(this, wxID_ANY);
//	wxBoxSizer* box = uaMethods::getSeatingSizer(panelSeating, plane1);
}