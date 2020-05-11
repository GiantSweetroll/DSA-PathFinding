#pragma once

#include "wx/wx.h"
#include "uaMain.h"

class uaApp : public wxApp
{
public:
	uaApp();
	~uaApp();

private:
	uaMain* frame = nullptr;

public:
	virtual bool OnInit();
};

