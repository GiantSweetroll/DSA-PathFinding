#pragma once

#include "wx/wx.h"
#include "wx/gbsizer.h"
#include "BetterPlane.h"

class uaMethods
{
public:
	uaMethods();
	~uaMethods();

public:
	static void insertFillers(wxGridSizer* sizer, int count);
	static wxBoxSizer* getSeatingSizer(wxWindow* parent, BetterPlane plane, SeatCoord seatHighlight);
	static BetterPlane initPlane1();
	static string getSeatNumber(SeatCoord c);
};

