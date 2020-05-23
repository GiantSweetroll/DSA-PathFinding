#pragma once

#include "Algorithms/Plane.h"

class BetterPlane : public Plane
{
	//Constructor
public:
	BetterPlane(int seatRows, int left, int middle, int right);
	~BetterPlane();

	//Fields
private:
	int left, middle, right, seatRows;

	//Methods
public:
	int getSeatRowsCount();
	int getLeftSeatsCount();
	int getRightSeatsCount();
	int getMiddleSeatsCount();
	void setLeftSeatsCount(int n);
	void setRightSeatsCount(int n);
	void setMiddleSeatsCount(int n);
	void setSeatRowsCount(int n);
	int** getEmergencyExits2DArray();
};

