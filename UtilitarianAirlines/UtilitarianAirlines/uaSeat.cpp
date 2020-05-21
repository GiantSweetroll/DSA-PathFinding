#include "uaSeat.h"
using namespace std;

uaSeat::uaSeat(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	btnBack = new wxButton(this, uaID::c_btnSeatBack, "Back");
}

uaSeat::~uaSeat()
{

}

void uaSeat::initSeating(int seatRows, int left, int right, int exits[][3])
{
	//Note: exits[][rowNumber, amount, pos(0=left, 1=right)]

	//Initialization
	panelSeating = new wxPanel(this, wxID_ANY);
	wxBoxSizer* box = uaMethods::getSeatingSizer(panelSeating, seatRows, left, right, exits);
}