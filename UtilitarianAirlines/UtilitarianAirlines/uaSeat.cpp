#include "uaSeat.h"

uaSeat::uaSeat(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	btnBack = new wxButton(this, uaID::c_btnSeatBack, "Back");
}

uaSeat::~uaSeat()
{

}