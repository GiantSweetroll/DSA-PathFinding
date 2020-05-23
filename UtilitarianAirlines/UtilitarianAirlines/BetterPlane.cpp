#include "BetterPlane.h"
#include "uaMethods.h"

BetterPlane::BetterPlane(int seatRows, int left, int middle, int right) : Plane(left + middle + right, seatRows)
{
	this->seatRows = seatRows;
	this->left = left;
	this->right = right;
	this->middle = middle;
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

int** BetterPlane::getEmergencyExits2DArray()
{
	LinkedList<SeatCoord> list = getEmergencyExits();
	int** array2d = uaMethods::create2DArray(getSeatRowsCount(), getLength());

	//For emergency exits with its own row, the index is -1 from the row after it.
	//For emergency exits on the same row as the seats, use that seat's row index.

	for (int i = 0, j=0; i < list.size(); i++)
	{
		SeatCoord c = list.get(i);
		//Check if it's a whole number
		if (floor(c.lengthAxis) == c.lengthAxis)
		{

		}
	}
}