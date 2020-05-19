#pragma once

#include "wx/wx.h"
#include "wx/gbsizer.h"

class uaMethods
{
public:
	uaMethods();
	~uaMethods();

public:
	static void insertFillers(wxGridSizer* sizer, int count);
	static wxGridSizer* getSeatingSizer(wxWindow* parent, int seatRows, int left, int right, int exits[][3]);
};

