#include "uaMethods.h"
using namespace std;

void uaMethods::insertFillers(wxGridSizer* sizer, int count)
{
	for (int i = 0; i < count; i++)
	{
		sizer->Add(1, 1, wxSizerFlags().Expand());
	}
}

wxGridSizer* uaMethods::getSeatingSizer(wxWindow* parent, int seatRows, int left, int right, int exits[][3])
{
	//Note: exits[][rowNumber, amount, pos(0=left, 1=right)]

	//Initialization
	wxGridSizer* grid = new wxGridSizer(left + right + 1, 1, 0);
	int spaceBetweenExits = left + right - 1;		//When there's two exits in one row
	int rowChar = 65;		//A -> Row alphabet
	int curExit = 0;

	//Add to sizer
	for (int i = 0; i < seatRows; i++)
	{
		//Check if exits needs to be made
		if (i == exits[curExit][0])
		{
			if (exits[curExit][1] == 1)
			{
				wxStaticBitmap* exit = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				if (exits[curExit][2] == 0)
				{
					grid->Add(exit, wxSizerFlags().Expand());
					uaMethods::insertFillers(grid, spaceBetweenExits+1);
				}
				else
				{
					uaMethods::insertFillers(grid, spaceBetweenExits + 1);
					grid->Add(exit, wxSizerFlags().Expand());
				}
			}
			else
			{
				wxStaticBitmap* exit1 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				wxStaticBitmap* exit2 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				grid->Add(exit1, wxSizerFlags().Expand());
				uaMethods::insertFillers(grid, spaceBetweenExits);
				grid->Add(exit2, wxSizerFlags().Expand());
			}
			curExit++;
		}

		//Draw left seating
		int seatNum = 1;
		for (int a = 0; a < left; a++)
		{
			wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER);
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum));
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			sizer->Add(text, wxSizerFlags().Center());
			panel->SetSizer(sizer);
			panel->Layout();
			grid->Add(panel, wxSizerFlags().Expand());
			seatNum++;
		}
		//Draw row alphabet
		char s = rowChar;
		grid->Add(new wxStaticText(parent, wxID_ANY, s), wxSizerFlags().Center());
		//Draw right seating
		for (int a = 0; a < right; a++)
		{
			wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER);
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum));
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			sizer->Add(text, wxSizerFlags().Center());
			panel->SetSizer(sizer);
			panel->Layout();
			grid->Add(panel, wxSizerFlags().Expand());
			seatNum++;
		}
		rowChar++;
	}
	//Draw exits at tail
	if (exits[curExit][0] == seatRows)
	{
		if (exits[curExit][1] == 1)
		{
			wxStaticBitmap* exit = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
			if (exits[curExit][2] == 0)
			{
				grid->Add(exit, wxSizerFlags().Expand());
				uaMethods::insertFillers(grid, spaceBetweenExits + 1);
			}
			else
			{
				uaMethods::insertFillers(grid, spaceBetweenExits + 1);
				grid->Add(exit, wxSizerFlags().Expand());
			}
		}
		else
		{
			wxStaticBitmap* exit1 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
			wxStaticBitmap* exit2 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
			grid->Add(exit1, wxSizerFlags().Expand());
			uaMethods::insertFillers(grid, spaceBetweenExits);
			grid->Add(exit2, wxSizerFlags().Expand());
		}
	}

	return grid;
}
