#include "uaCanvas.h"

uaCanvas::uaCanvas(wxWindow* parent, wxBitmap image)
{
	Create(parent, wxID_ANY);

	SetBackgroundBitmap(image);
}

uaCanvas::~uaCanvas()
{

}