#pragma once

#include "Algorithms/Passenger.h"

class BetterPassenger: public Passenger
{
	//Constructor
public:
	BetterPassenger();
	BetterPassenger(string firstName, string lastName, string email, Gender gender, int age, double weightKilos, double heightMeters, bool pregnant, Disabilities disabilities);
	~BetterPassenger();
	
	//Fields
private:
	string firstName, lastName, email;

	//Methods
public:
	string getFirstName();
	string getLastName();
	string getEmail();
	void setFirstName(string s);
	void setLastName(string s);
	void setEmail(string s);
};

