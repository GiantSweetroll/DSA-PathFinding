#include "uaMethods.h"
using namespace std;

void uaMethods::insertFillers(wxGridSizer* sizer, int count)
{
	for (int i = 0; i < count; i++)
	{
		sizer->Add(1, 1, wxSizerFlags().Expand());
	}
}

wxBoxSizer* uaMethods::getSeatingSizer(wxWindow* parent, int seatRows, int left, int middle, int right, int exits[][3])
{
	//Note: exits[][rowNumber, amount, pos(0=left, 1=right)]

	//Initialization
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	int spaceBetweenExits = left + middle + right;		//When there's two exits in one row
	int rowChar = 65;		//A -> Row alphabet
	int curExit = 0;

	//Add to sizer
	for (int i = 0; i < seatRows; i++)
	{
		//Check if exits needs to be made
		if (i == exits[curExit][0])
		{
			wxGridSizer* exitSizer = new wxGridSizer(left + middle + right + 2, 1, 0);
			if (exits[curExit][1] == 1)
			{
				wxStaticBitmap* exit = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				if (exits[curExit][2] == 0)
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
			wxPanel* panel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER);
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum));
			text->SetFont(*seatFont);
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			sizer->Add(text, wxSizerFlags().Center());
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
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum));
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			text->SetFont(*seatFont);
			sizer->Add(text, wxSizerFlags().Center());
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
			wxStaticText* text = new wxStaticText(panel, wxID_ANY, to_string(seatNum));
			wxGridSizer* sizer = new wxGridSizer(1, 0, 0);
			text->SetFont(*seatFont);
			sizer->Add(text, wxSizerFlags().Center());
			panel->SetSizer(sizer);
			panel->Layout();
			seatsSizer->Add(panel, wxSizerFlags().Expand());
			seatNum++;
		}
		rowChar++;
		sizer->Add(seatsSizer, wxSizerFlags().Expand());
	}
	//Draw exits at tail
	if (exits[curExit][0] == seatRows)
	{
		wxGridSizer* exitSizer = new wxGridSizer(left + right + 1, 1, 0);
		if (exits[curExit][1] == 1)
		{
			wxStaticBitmap* exit = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
			if (exits[curExit][2] == 0)
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

int** uaMethods::create2DArray(unsigned height, unsigned width)
{
	{
		//https://stackoverflow.com/questions/8617683/return-a-2d-array-from-a-function
		int** array2D = 0;
		array2D = new int* [height];

		for (int h = 0; h < height; h++)
		{
			array2D[h] = new int[width];

			for (int w = 0; w < width; w++)
			{
				// fill in some initial values
				// (filling in zeros would be more logic, but this is just for the example)
				array2D[h][w] = w + width * h;
			}
		}

		return array2D;
	}
}
