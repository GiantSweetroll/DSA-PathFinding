#include "BetterPlane.h"
#include <wx\msgdlg.h>

BetterPlane::BetterPlane(int seatRows, int left, int middle, int right) : Plane(left + middle + right, seatRows)
{
	this->seatRows = seatRows;
	this->left = left;
	this->right = right;
	this->middle = middle;
	passengerSeatMap = new map<string, SeatCoord>();
}

BetterPlane::~BetterPlane()
{

}

int BetterPlane::getLeftSeatsCount()
{
	return left;
}

int BetterPlane::getSeatRowsCount()
{
	return seatRows;
}

int BetterPlane::getRightSeatsCount()
{
	return right;
}

int BetterPlane::getMiddleSeatsCount()
{
	return middle;
}

void BetterPlane::setLeftSeatsCount(int n)
{
	left = n;
}

void BetterPlane::setRightSeatsCount(int n)
{
	right = n;
}

void BetterPlane::setMiddleSeatsCount(int n)
{
	middle = n;
}

void BetterPlane::setSeatRowsCount(int n)
{
	seatRows = n;
}

LinkedList<LinkedList<int>> BetterPlane::getEmergencyExitsArray2()
{
	LinkedList<SeatCoord> list = getEmergencyExits();
	LinkedList<LinkedList<int>>* newList = new LinkedList<LinkedList<int>>();
	map<int, LinkedList<int>> map;

	//For emergency exits with its own row, the index is -1 from the seat row after it.
	//For emergency exits on the same row as the seats, use that seat's row index.

	for (int i = 0, j=0; i < list.size(); i++)
	{
		SeatCoord c = list.get(i);
		LinkedList<int>* subList = new LinkedList<int>();
		
		//Check if it's a whole number. Whole number means it's in the same row as the seats. Decimal means it is its own row.
		if (floor(c.lengthAxis) == c.lengthAxis)
		{
			subList->add((int)c.lengthAxis);
		}
		else
		{
			//Decimal
			subList->add(floor(c.lengthAxis));
		}
		subList->add(1);
		//Left or right?
		if (c.widthAxis == 0)
		{
			//Left
			subList->add(0);
		}
		else
		{
			//Right
			subList->add(1);
		}

		//Check if emergency exit already exists
		if (map.find(subList->get(0)) != map.end())
		{
			//If exists
			j = subList->get(0);
			map[j].update(1, 2);
		}
		else
		{
			map.insert(pair<int, LinkedList<int>>(subList->get(0), *subList));
		}
	}

	//Convert to linkedlist 2d
	for (const auto& entry : map)
	{
		newList->add(entry.second);
	}

	return *newList;
}

void BetterPlane::addCustomPassenger(BetterPassenger passenger)
{
	Plane::addCustomPassenger(passenger);
	Plane::generate();
	LinkedList<SeatCoord> list = Plane::getCustomPassengerPos();
	passengerSeatMap->insert(pair<string, SeatCoord>(passenger.getEmail(), list.get(list.size() - 1)));
}

SeatCoord BetterPlane::getCustomPassengerSeat(string email)
{
	return passengerSeatMap->find(email)->second;
}