#pragma once

#include "wx/wx.h"
#include "uaMainMenu.h"

class uaMain : public wxFrame
{
	//Constructors
public:
	uaMain();
	~uaMain();

	//Fields
public:
	const int c_wWidth = 800;
	const int c_wHeight = 600;
private:
	uaMainMenu* mainMenu = nullptr;		//Main Menu
};

