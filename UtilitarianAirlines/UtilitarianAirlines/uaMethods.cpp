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
	wxGridSizer* grid = new wxGridSizer(left + right + 1, 5, 0);
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
					grid->Add(exit, wxSizerFlags().Expand().Center());
				}
				else
				{
					for (int i = 0; i < left; i++)
					{
						grid->Add(1, 1, wxSizerFlags().Expand());
					}
					grid->Add(1, 1, wxSizerFlags().Expand());
					for (int i = 1; i < right; i++)
					{
						grid->Add(1, 1, wxSizerFlags().Expand());
					}
					grid->Add(exit, wxSizerFlags().Expand().Center());
				}
			}
			else
			{
				//2 exits
			}
			{
				wxStaticBitmap* exit1 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				wxStaticBitmap* exit2 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
				grid->Add(exit1, wxSizerFlags().Expand().Center());
				for (int i = 1; i < left; i++)
				{
					grid->Add(1, 1, wxSizerFlags().Expand());
				}
				grid->Add(1, 1, wxSizerFlags().Expand());
				for (int i = 1; i < right; i++)
				{
					grid->Add(1, 1, wxSizerFlags().Expand());
				}
				grid->Add(exit2, wxSizerFlags().Expand().Center());
			}
			curExit++;
		}

		//Draw left seating
		int seatNum = 1;
		for (int a = 0; a < left; a++)
		{
			wxStaticText* text = new wxStaticText(parent, wxID_ANY, to_string(seatNum));
			grid->Add(text, wxSizerFlags().Expand().Center());
			seatNum++;
		}
		//Draw row alphabet
		char s = rowChar;
		grid->Add(new wxStaticText(parent, wxID_ANY, s), wxSizerFlags().Expand().Center());
		//Draw right seating
		for (int a = 0; a < right; a++)
		{
			wxStaticText* text = new wxStaticText(parent, wxID_ANY, to_string(seatNum));
			grid->Add(text, wxSizerFlags().Expand().Center());
			seatNum++;
		}
	}
	//Draw exits at tail
	if (exits[curExit][1] == 1)
	{
		wxStaticBitmap* exit = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
		if (exits[curExit][2] == 0)
		{
			grid->Add(exit, wxSizerFlags().Expand().Center());
		}
		else
		{
			for (int i = 0; i < left; i++)
			{
				grid->Add(1, 1, wxSizerFlags().Expand());
			}
			grid->Add(1, 1, wxSizerFlags().Expand());
			for (int i = 1; i < right; i++)
			{
				grid->Add(1, 1, wxSizerFlags().Expand());
			}
			grid->Add(exit, wxSizerFlags().Expand().Center());
		}
	}
	else
	{
		//2 exits
	}
	{
		wxStaticBitmap* exit1 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
		wxStaticBitmap* exit2 = new wxStaticBitmap(parent, wxID_ANY, wxBitmap("exit.bmp", wxBITMAP_TYPE_BMP));
		grid->Add(exit1, wxSizerFlags().Expand().Center());
		for (int i = 1; i < left; i++)
		{
			grid->Add(1, 1, wxSizerFlags().Expand());
		}
		grid->Add(1, 1, wxSizerFlags().Expand());
		for (int i = 1; i < right; i++)
		{
			grid->Add(1, 1, wxSizerFlags().Expand());
		}
		grid->Add(exit2, wxSizerFlags().Expand().Center());
	}

	return grid;
}
