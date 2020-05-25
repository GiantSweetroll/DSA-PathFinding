#pragma once

#include <stdlib.h>
#include <memory>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>
#include "LinkedList.h"
#include "Passenger.h"
#include "BST.h"
#include "SeatCoord.h"
#include "RandomUtil.h"
#include <tuple>

#include <fstream>
#include <sstream>

using namespace std;

class Plane {

protected:

    LinkedList<Passenger> passengerList; // Random passengers
    LinkedList<Passenger> customPassengerList; // Custom passengers
    LinkedList<LinkedList<Passenger>> passengers;
    LinkedList<SeatCoord> emergencyExits;
    int length;
    int width;

    bool generated = false;

private:
    // To make sorting easier, use a struct.
    struct SeatToExit {
        SeatToExit() {}
        SeatToExit(SeatCoord seat, double dist) {this->seat = seat; this->dist = dist;}
        SeatCoord seat;
        double dist;
    };


public:

    Plane(int length, int width) {
        // Constructor to fill the plane
        this->length = length;
        this->width = width;
    }

    ~Plane() {} // Constructor to delete the object

    int getLength() {
        return length;
    }

    int getWidth() {
        return width;
    }

    int getSize() {
        return width * length;
    }

    bool isGenerated() {
        return generated;
    }

    // This function generates a layout based on all of the custom passengers + all in the passengerTree.
    // If the amount does not match the width * length of the plane, the seat will be EMPTY.
    void generate() {
        /* Generates width * length amount of passenger objects, and puts them in the LinkedList
        If invoked when already generated, regenerate all the passengers. If "you" is filled, then use it.
        */

       // Clears the main seating layout
        passengers.clearList();

        BST<Passenger> sortedPassengers = BST<Passenger>();

        int repetition = Rand::clampNum(customPassengerList.size(), 0, (length * width));
        // Adds all the custom passengers to the BST
        for (int i = 0; i < repetition; i++) {
            sortedPassengers.insert(customPassengerList.get(i));
        }

        repetition = Rand::clampNum(passengerList.size(), 0, (length * width) - sortedPassengers.getSize());
        // Adds all of the passengers into the BST. If overflows, then just insert until full.
        for (int i = 0; i < repetition; i++) {
            sortedPassengers.insert(passengerList.get(i));
        }
    
        // Generates the rest as "empty" passengers.
        int emptySeats = (length * width) - sortedPassengers.getSize();
        repetition = Rand::clampNum(emptySeats, 0, numeric_limits<int>().max());
        for (int i = 0; i < repetition; i++) {
            sortedPassengers.insert(Passenger());
        }

        // End of generation

        // If there is no emergency exits added, add a default one at (0, 0)
        if (emergencyExits.size() == 0) {
            emergencyExits.add(SeatCoord(0, 0));
        }

        // Sorting mechanism of the seat based on their location from the emergency exit.
        // With LinkedList to store the seat data, and sorting using Insertion Sort.
        LinkedList<SeatToExit> orderedSeating = LinkedList<SeatToExit>();
        for (int i = 0; i < length; i++) {
            // Loops the length of the seats.
            for (int j = 0; j < width; j++) {
                // Loops the width of the seats.
                // Distance used is not squared, to save computing power.
                double curDistance = numeric_limits<double>().max(); // Distance from the seat to the nearest exit.
                // Loops all the emergency exits.
                for (int s = 0; s < emergencyExits.size(); s++) {
                    // Checks the closest emergency exit from the current seat, and sets it into distance
                    double tempDist = pow((emergencyExits.get(s).lengthAxis - i), 2) + pow((emergencyExits.get(s).widthAxis - j), 2);
                    if (tempDist < curDistance) { curDistance = tempDist; } // Assigns to variable
                }
                // Do insertion sort here to the linked list.
                // If orderedSeating size is 0, just insert into the list and restart for loop.
                if (orderedSeating.size() == 0) { orderedSeating.add(SeatToExit(SeatCoord(i, j), curDistance)); continue; }
                // Loops in the orderedSeating
                for (int s = 0; s < orderedSeating.size(); s++) {
                    // sort in DESCENDING order.
                    // compare with current distance
                    if (orderedSeating.get(s).dist < curDistance) {
                        orderedSeating.insert(s, SeatToExit(SeatCoord(i, j), curDistance));
                        break;
                    }
                    // if loop has reached end of index without inserting then
                    if (s == (orderedSeating.size() - 1)) {
                        // Insert to the last value.
                        orderedSeating.insert(orderedSeating.size(), SeatToExit(SeatCoord(i, j), curDistance));
                        break;
                    }
                }

            }
        }
        // End of sorting.

        // Fills the passengers linkedlist with bogus value.
        for (int i = 0; i < length; i++) {
            LinkedList<Passenger> temp = LinkedList<Passenger>();
            for (int j = 0; j < width; j++) {
                temp.add(Passenger());
            }
            passengers.add(temp);
        }
        // End of bogus value assignment

        // Adds all of the sorted passengers based on their mmrs to their seating.
        // Returns the previous BST data.
        LinkedList<Passenger> orderedPassengerList = sortedPassengers.returnInOrder();

        for (int i = 0; i < orderedSeating.size(); i++) {
            passengers.get( orderedSeating.get(i).seat.lengthAxis ).update( orderedSeating.get(i).seat.widthAxis, orderedPassengerList.get(i) );
        }
        generated = true;
    }

    LinkedList<LinkedList<Passenger>> getPassengerLayout() {
        // Gets all of the passenger in layout, if already generated.
        LinkedList<LinkedList<Passenger>> pass;
        if (generated) {
            return passengers;
        }
        return pass;
    }

    void addToPassengers(Passenger passenger) {
        passengerList.add(passenger);
    }

    void addCustomPassenger(Passenger passenger) {
        customPassengerList.add(passenger);
    }

    void addCustomPassengers(LinkedList<Passenger> passengers) {
        for (int i = 0; i < passengers.size(); i++) {
            customPassengerList.add(passengers.get(i));
        }
    }

    LinkedList<SeatCoord> getCustomPassengerPos() {
        LinkedList<SeatCoord> seats;
        if (generated) {
        for (int i = 0; i < passengers.size(); i++) {
            // Looping through the length
        for (int j = 0; j < passengers.get(i).size(); j++) {
            // Looping through the width
            for (int x = 0; x < customPassengerList.size(); x++) {
                // Looping through custom passengers
                if(passengers.get(i).get(j).getMMR() == customPassengerList.get(x).getMMR()) {
                    seats.add(SeatCoord(i, j));
                }
            }
        }
        }
        }
        return seats;
    }

    LinkedList<tuple<Passenger, SeatCoord>> getCustomPassengerAndPos() {

        LinkedList<tuple<Passenger, SeatCoord>> data;
                if (generated) {
        for (int i = 0; i < passengers.size(); i++) {
            // Looping through the length
        for (int j = 0; j < passengers.get(i).size(); j++) {
            // Looping through the width
            for (int x = 0; x < customPassengerList.size(); x++) {
                // Looping through custom passengers
                if(passengers.get(i).get(j).getMMR() == customPassengerList.get(x).getMMR()) {
                    // Make tuple and insert into list
                    data.add(make_tuple(passengers.get(i).get(j), SeatCoord(i, j)));
                }
            }
        }
        }
        }
        return data;
    }

    void clearCustomPassengers() {
        customPassengerList.clearList();
    }

    void addEmergencyExit(int lengthAxis, int widthAxis) {
        emergencyExits.add(SeatCoord(lengthAxis, widthAxis));
    }

    LinkedList<SeatCoord> getEmergencyExits() {
        return emergencyExits;
    }

    void clearEmergencyExit() {
        emergencyExits.clearList();
    }

    // Debug Stuff
    void printGeneratedPassengers() {

        cout << "Length V, Width ->" << endl;

        if (passengers.size() == 0 ) {
            cout << "Not generated yet !" << endl;
            return;
        }

        cout << " ";

        for (int i = 0; i < passengers.get(0).size(); i++) {
            cout << "         " << i;
        }

        cout << endl;

        for (int i = 0; i < passengers.size(); i++) {
            // Looping through the length
            cout << setw(3) << i << " ";
            for (int j = 0; j < passengers.get(i).size(); j++) {
                // Looping through the width
                // cout << setfill(' ') << setw(5) << (round(passengers.get(i).get(j).getMMR() * 1000.0) / 1000.0) << " "; // rounded
                string passStr = (passengers.get(i).get(j).getMMR() == -100.0) ? "EMPTY" : to_string(passengers.get(i).get(j).getMMR());
                cout << setfill(' ') << setw(9) << passStr << " "; // not rounded
            }
            cout << endl;
        }


        // Prints the exit points
        for (int i = 0; i < emergencyExits.size(); i++) {
            cout << "(" << emergencyExits.get(i).lengthAxis << ", " << emergencyExits.get(i).widthAxis << ")" << endl;
        }
    }
	
	LinkedList<Passenger> getCustomPassengerList() {
		return customPassengerList;
	}

    // File parser methods
    void savePassengerData(string fileName) {
        ofstream fileOut(fileName);

        fileOut << length << " " << width << "\n";
        fileOut << "#" << "\n";

        // Passenger save format:
        // age gender weight height pregnant disabilities
        for (int i = 0; i < customPassengerList.size(); i++) {
            Passenger ref = customPassengerList.get(i);
            fileOut << ref.getAge() << " " << ref.getGender() << " " << ref.getWeight()
            << " " << ref.getHeight() << " " << ref.isPregnant() << " " << ref.getDisabilities() << " " << "\n";
        }

        fileOut << "#" << "\n";
        
        for (int i = 0; i < passengerList.size(); i++) {
            Passenger ref = passengerList.get(i);
            fileOut << ref.getAge() << " " << ref.getGender() << " " << ref.getWeight()
            << " " << ref.getHeight() << " " << ref.isPregnant() << " " << ref.getDisabilities() << " " << "\n";
        }

        fileOut << "#" << "\n";

        for (int i = 0; i < emergencyExits.size(); i++) {
            SeatCoord ref = emergencyExits.get(i);
            fileOut << ref.lengthAxis << " " << ref.widthAxis << "\n";
        }

        fileOut.close();
    }

    void loadPassengerData(string fileName) {
        // Passenger save format:
        // age gender weight height pregnant disabilities

        ifstream fileIn(fileName);
        // Clears all the linkedList data
        customPassengerList.clearList();
        passengerList.clearList();
        emergencyExits.clearList();

        string nextLine;
        int step = 0;
        
        // Reads from the data.
        while (getline(fileIn, nextLine)) {
            LinkedList<string> pass;
            std::istringstream iss(nextLine);

            bool restart = false;

            for (string s; iss >> s;) {
                pass.add(s);
                if (s == "#") {
                    step++;
                    restart = true;
                }
            }

            // Restart stream.
            if (restart) {
                continue;
            }

            // Which action is it going to take.
            switch (step) {
                case 0:
                // Add to custom passenger list
                length = stoi(pass.get(0));
                width = stoi(pass.get(1));
                break;

                case 1:
                // Add to custom passenger list
                customPassengerList.add(Passenger(static_cast<Passenger::Gender>(stoi(pass.get(1))), stoi(pass.get(0)), stod(pass.get(2)), stod(pass.get(3)),
                (bool)stoi(pass.get(4)), (Passenger::Disabilities)stoi(pass.get(5))));
                break;

                case 2:
                // Add to general passengers
                passengerList.add(Passenger(static_cast<Passenger::Gender>(stoi(pass.get(1))), stoi(pass.get(0)), stod(pass.get(2)), stod(pass.get(3)),
                (bool)stoi(pass.get(4)), (Passenger::Disabilities)stoi(pass.get(5))));
                break;

                default:
                // Add emergency exits
                emergencyExits.add(SeatCoord(stoi(pass.get(0)), stoi(pass.get(1))));
            }

        }
        generated = false;
    }

};