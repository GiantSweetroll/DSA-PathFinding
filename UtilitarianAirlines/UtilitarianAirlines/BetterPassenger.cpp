#include "BetterPassenger.h"

BetterPassenger::BetterPassenger(string firstName, string lastName, string email, Gender gender, int age, double weightKilos, double heightMeters, bool pregnant, Disabilities disabilities) : Passenger(gender, age, weightKilos, heightMeters, pregnant, disabilities)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
}

BetterPassenger::~BetterPassenger()
{}

string BetterPassenger::getFirstName()
{
	return firstName;
}

string BetterPassenger::getLastName()
{
	return lastName;
}

string BetterPassenger::getEmail()
{
	return email;
}

void BetterPassenger::setFirstName(string s)
{
	firstName = s;
}

void BetterPassenger::setLastName(string s)
{
	lastName = s;
}

void BetterPassenger::setEmail(string s)
{
	email = s;
}