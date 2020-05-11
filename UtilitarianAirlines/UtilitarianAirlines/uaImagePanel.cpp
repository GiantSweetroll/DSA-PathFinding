#include "uaImagePanel.h"

BEGIN_EVENT_TABLE(uaImagePanel, wxPanel)
	EVT_PAINT(uaImagePanel::paintEvent)
END_EVENT_TABLE()

uaImagePanel::uaImagePanel(wxFrame* parent, wxString file, wxBitmapType format):wxPanel(parent)
{
	image.LoadFile(file, format);
}

void uaImagePanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void uaImagePanel::render(wxDC& dc)
{
    dc.DrawBitmap(image, 0, 0, false);
}