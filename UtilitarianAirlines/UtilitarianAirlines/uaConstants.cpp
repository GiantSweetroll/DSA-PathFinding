#include "uaConstants.h"

BetterPlane uaConstants::initPlane1()
{
	int seatRows = 8;
	int left = 3;
	int middle = 4;
	int right = 3;
	BetterPlane plane = BetterPlane(seatRows, left, middle, right);

	plane.addEmergencyExit(0, -0.5);
	plane.addEmergencyExit(0, 5.5);
	plane.addEmergencyExit(left + middle + right, 5.5);

	return plane;
}