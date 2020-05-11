#include "uaApp.h"

wxIMPLEMENT_APP(uaApp);

uaApp::uaApp()
{

}

uaApp::~uaApp()
{

}

bool uaApp::OnInit()
{
	frame = new uaMain();
	frame->Show();

	return true;
}