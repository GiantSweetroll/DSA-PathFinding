#pragma once

#include "Algorithms/Plane.h"
#include <map>
#include "Algorithms/LinkedList.h"
#include "BetterPassenger.h"

class BetterPlane : public Plane
{
	//Constructor
public:
	BetterPlane(int seatRows, int left, int middle, int right);
	~BetterPlane();

	//Fields
private:
	int left, middle, right, seatRows;
	LinkedList<BetterPassenger> customBetterPassengerList;

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
	void addCustomPassenger(BetterPassenger passenger);
	LinkedList<LinkedList<int>> getEmergencyExitsArray2();
	SeatCoord* getCustomPassengerSeat(string email);
	bool passengerExists(string email);
};

