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
	int spaceBetweenExits = left + middle + right;		//When there's two exits in one row
	int rowChar = 65;		//A -> Row alphabet
	int curExit = 0;

	//Add to sizer
	for (int i = 0; i < seatRows; i++)
	{
		//Check if exits needs to be made
		if (curExit < exits.size() && i == exits.get(curExit).get(0))
		{
			wxGridSizer* exitSizer = new wxGridSizer(left + middle + right + 2, 1, 0);
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
		wxGridSizer* seatsSizer = new wxGridSizer(left + middle + right + 2, 1, 0);
		wxFont* seatFont = new wxFont(35, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
		int seatNum = 1;
		for (int a = 0; a < left; a++)
		{
			wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
			text->SetFont(*seatFont);
			if (seatHighlight.lengthAxis == i && seatHighlight.widthAxis == seatNum-1)
			{
				text->SetBackgroundColour(wxColour(255, 0, 0, 255));
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
				text->SetBackgroundColour(wxColour(255, 0, 0, 255));
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
				text->SetBackgroundColour(wxColour(255, 0, 0, 255));
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
		wxGridSizer* exitSizer = new wxGridSizer(left + right + 1, 1, 0);
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

	plane.addEmergencyExit(0, 0);
	plane.addEmergencyExit(5, 0);
	plane.addEmergencyExit(5, left + middle + right);
	plane.addEmergencyExit(3, left + middle + right);

	return plane;
}

string uaMethods::getSeatNumber(SeatCoord c)
{
	char cc = 65 + c.lengthAxis;

	return string(1, cc) + to_string((int)(c.widthAxis + 1));
}