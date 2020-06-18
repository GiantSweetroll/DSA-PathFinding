#include "uaMethods.h"
using namespace std;

void uaMethods::insertFillers(wxGridSizer* sizer, int count)
{
	for (int i = 0; i < count; i++)
	{
		sizer->Add(1, 1, wxSizerFlags().Expand());
	}
}

wxBoxSizer* uaMethods::getSeatingSizer(wxWindow* parent, BetterPlane plane, SeatCoord seatHighlight)
{
	//Note: exits[][rowNumber, amount, pos(0=left, 1=right)]

	//Initialization
	int seatRows = plane.getSeatRowsCount();
	int left = plane.getLeftSeatsCount();
	int middle = plane.getMiddleSeatsCount();
	int right = plane.getRightSeatsCount();
	LinkedList<LinkedList<int>> exits = plane.getEmergencyExitsArray2();
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	int spaceBetweenExits = left + middle + right + 2;		//When there's two exits in one row
	int rowChar = 65;		//A -> Row alphabet
	int curExit = 0;

	//Add to sizer
	for (int i = 0; i < seatRows; i++)
	{
		//Check if exits needs to be made
		if (curExit < exits.size() && i == exits.get(curExit).get(0))
		{
			wxGridSizer* exitSizer = new wxGridSizer(left + middle + right + 4, 1, 0);
			if (exits.get(curExit).get(1) == 1)
			{
				wxStaticBitmap* exit = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				if (exits.get(curExit).get(2) == 0)
				{
					exitSizer->Add(exit, wxSizerFlags().Expand());
					uaMethods::insertFillers(exitSizer, spaceBetweenExits+1);
				}
				else
				{
					uaMethods::insertFillers(exitSizer, spaceBetweenExits + 1);
					exitSizer->Add(exit, wxSizerFlags().Expand());
				}
			}
			else
			{
				wxStaticBitmap* exit1 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				wxStaticBitmap* exit2 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				exitSizer->Add(exit1, wxSizerFlags().Expand());
				uaMethods::insertFillers(exitSizer, spaceBetweenExits);
				exitSizer->Add(exit2, wxSizerFlags().Expand());
			}
			curExit++;
			sizer->Add(exitSizer);
		}

		//Draw left seating
		wxGridSizer* seatsSizer = new wxGridSizer(left + middle + right + 4, 1, 0);
		wxFont* seatFont = new wxFont(35, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
		int seatNum = 1;
		uaMethods::insertFillers(seatsSizer, 1);
		for (int a = 0; a < left; a++)
		{
			wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
			text->SetFont(*seatFont);
			if (seatHighlight.lengthAxis == i && seatHighlight.widthAxis == seatNum-1)
			{
				text->SetBackgroundColour(wxColour(96, 155, 231, 255));
				text->SetForegroundColour(wxColour(255, 255, 255, 255));
			}
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			sizer->Add(text, wxSizerFlags().Expand());
			panel->SetSizer(sizer);
			panel->Layout();
			seatsSizer->Add(panel, wxSizerFlags().Expand());
			seatNum++;
		}
		//Draw row alphabet
		char s = rowChar;
		wxStaticText* alphabet = new wxStaticText(parent, wxID_ANY, s);
		alphabet->SetFont(*seatFont);
		alphabet->SetForegroundColour(wxColour(0, 102, 255, 255));
		seatsSizer->Add(alphabet, wxSizerFlags().Center());
		//Draw middle seating
		for (int a = 0; a < middle; a++)
		{
			wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER);
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			text->SetFont(*seatFont);
			if (seatHighlight.lengthAxis == i && seatHighlight.widthAxis == seatNum - 1)
			{
				text->SetBackgroundColour(wxColour(96, 155, 231, 255));
				text->SetForegroundColour(wxColour(255, 255, 255, 255));
			}
			sizer->Add(text, wxSizerFlags().Expand());
			panel->SetSizer(sizer);
			panel->Layout();
			seatsSizer->Add(panel, wxSizerFlags().Expand());
			seatNum++;
		}
		//Draw row alphabet again
		s = rowChar;
		wxStaticText* alphabet2 = new wxStaticText(parent, wxID_ANY, s);
		alphabet2->SetFont(*seatFont);
		alphabet2->SetForegroundColour(wxColour(0, 102, 255, 255));
		seatsSizer->Add(alphabet2, wxSizerFlags().Center());
		//Draw right seating
		for (int a = 0; a < right; a++)
		{
			wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER);
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			text->SetFont(*seatFont);
			if (seatHighlight.lengthAxis == i && seatHighlight.widthAxis == seatNum - 1)
			{
				text->SetBackgroundColour(wxColour(96, 155, 231, 255));
				text->SetForegroundColour(wxColour(255, 255, 255, 255));
			}
			sizer->Add(text, wxSizerFlags().Expand());
			panel->SetSizer(sizer);
			panel->Layout();
			seatsSizer->Add(panel, wxSizerFlags().Expand());
			seatNum++;
		}
		rowChar++;
		sizer->Add(seatsSizer, wxSizerFlags().Expand());
	}
	//Draw exits at tail
	if (curExit < exits.size() && exits.get(curExit).get(0) == seatRows)
	{
		wxGridSizer* exitSizer = new wxGridSizer(left + middle + right + 4, 1, 0);
		if (exits.get(curExit).get(1) == 1)
		{
			wxStaticBitmap* exit = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
			if (exits.get(curExit).get(2) == 0)
			{
				exitSizer->Add(exit, wxSizerFlags().Expand());
				uaMethods::insertFillers(exitSizer, spaceBetweenExits + 1);
			}
			else
			{
				uaMethods::insertFillers(exitSizer, spaceBetweenExits + 1);
				exitSizer->Add(exit, wxSizerFlags().Expand());
			}
		}
		else
		{
			wxStaticBitmap* exit1 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
			wxStaticBitmap* exit2 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
			exitSizer->Add(exit1, wxSizerFlags().Expand());
			uaMethods::insertFillers(exitSizer, spaceBetweenExits);
			exitSizer->Add(exit2, wxSizerFlags().Expand());
		}
		curExit++;
		sizer->Add(exitSizer);
	}

	return sizer;
}


BetterPlane uaMethods::initPlane1()
{
	int seatRows = 8;
	int left = 3;
	int middle = 4;
	int right = 3;
	BetterPlane plane = BetterPlane(seatRows, left, middle, right);

	plane.addEmergencyExit(5, 0);
	plane.addEmergencyExit(5, left + middle + right);
	plane.addEmergencyExit(3, 0);
	plane.addEmergencyExit(3, left + middle + right);

	//Add random passenger
	for (int i = 0; i < plane.getSize() - 3; i++)
	{
		plane.addToPassengers(Passenger::randomPassenger());
	}

	return plane;
}

string uaMethods::getSeatNumber(SeatCoord c)
{
	char cc = 65 + c.lengthAxis;

	return string(1, cc) + to_string((int)(c.widthAxis + 1));
}

wxPanel* uaMethods::initBasicPanelSeat(wxWindow* parent, bool regis, BetterPlane plane, string email)
{
	//Initialization
	wxPanel* panelSeat = new wxPanel(parent, wxID_ANY);
	wxButton* btnBackSeat = nullptr;
	wxButton* btnMainMenu = regis? new wxButton(panelSeat, uaID::c_btnRegMainMenu, "Main Menu") : new wxButton(panelSeat, uaID::c_btnSeatBack, "Main Menu");
	SeatCoord passengerSeat = *plane.getCustomPassengerSeat(email);
	wxStaticText* stSeatNum = new wxStaticText(panelSeat, wxID_ANY, uaMethods::getSeatNumber(passengerSeat));
	wxStaticText* st1 = regis? new wxStaticText(panelSeat, wxID_ANY, "According to your registration your seat will be at:") : new wxStaticText(panelSeat, wxID_ANY, "Welcome back! Your seat will be at:");
	wxStaticText* st2 = new wxStaticText(panelSeat, wxID_ANY, "Please enjoy your flight,\nThank you for choosing");
	wxStaticText* st3 = new wxStaticText(panelSeat, wxID_ANY, "Utilitarian Airlines");
	wxStaticText* st4 = new wxStaticText(panelSeat, wxID_ANY, "Remember to always check your seat because it might change\naccording to others, we will be sending you an email of the final\nseating 3 days before the flight.\nThank you.");
	wxBoxSizer* seating = uaMethods::getSeatingSizer(panelSeat, plane, passengerSeat);
	wxBoxSizer* leftBox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* btnBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);
	wxFont basicFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	//Properties
	panelSeat->SetBackgroundColour(*wxWHITE);
	st1->SetFont(basicFont);
	st1->SetForegroundColour(wxColour(51, 108, 252, 255));
	st2->SetFont(basicFont);
	st2->SetForegroundColour(wxColour(51, 108, 252, 255));
	st3->SetFont(wxFont(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	st3->SetForegroundColour(wxColour(51, 108, 252, 255));
	st4->SetFont(basicFont);
	st4->SetForegroundColour(wxColour(154, 176, 253, 255));
	stSeatNum->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	stSeatNum->SetForegroundColour(wxColour(51, 108, 252, 255));
	btnMainMenu->SetFont(basicFont);
	btnMainMenu->SetForegroundColour(wxColour(255, 255, 255, 255));
	btnMainMenu->SetBackgroundColour(wxColour(11, 83, 165, 255));
	panelSeat->Hide();

	//Add to sizer
	btnBox->Add(btnMainMenu);
	leftBox->Add(st1);
	leftBox->Add(stSeatNum);
	leftBox->Add(st2);
	leftBox->Add(st3);
	leftBox->Add(st4);
	leftBox->AddSpacer(10);
	leftBox->Add(btnBox);
	box->Add(leftBox);
	box->AddSpacer(20);
	box->Add(seating);

	panelSeat->SetSizer(box);
	panelSeat->Layout();

	return panelSeat;
}