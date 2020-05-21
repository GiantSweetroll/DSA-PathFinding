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

using namespace std;

class Plane {

private:

    LinkedList<Passenger> passengerList; // Random passengers
    LinkedList<Passenger> customPassengerList; // Custom passengers
    LinkedList<LinkedList<Passenger>> passengers;
    LinkedList<SeatCoord> emergencyExits;
    int length;
    int width;

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

    // This function generates a layout based on all of the custom passengers + all in the passengerTree.
    // If the amount does not match the width * length of the plane, the seat will be EMPTY.
    void generate() {
        /* Generates width * length amount of passenger objects, and puts them in the LinkedList
        If invoked when already generated, regenerate all the passengers. If "you" is filled, then use it.
        */

       // Clears the main seating layout
        passengers.clearList();

        BST<Passenger> sortedPassengers = BST<Passenger>();

        // Adds all the custom passengers to the BST
        for (int i = 0; i < clamp(customPassengerList.size(), 0, (length * width)); i++) {
            sortedPassengers.insert(customPassengerList.get(i));
        }

        // Adds all of the passengers into the BST. If overflows, then just insert until full.
        for (int i = 0; i < clamp(passengerList.size(), 0, (length * width) - sortedPassengers.getSize()); i++) {
            sortedPassengers.insert(passengerList.get(i));
        }

        // Generates the rest as "empty" passengers.
        int emptySeats = (length * width) - sortedPassengers.getSize();
        for (int i = 0; i < clamp(emptySeats, 0, numeric_limits<int>().max()); i++) {
            sortedPassengers.insert(Passenger());
        }
        cout << sortedPassengers.getSize() << endl;

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

    void clearCustomPassengers() {
        customPassengerList.clearList();
    }

    bool addEmergencyExit(int lengthAxis, int widthAxis) {
        if ((lengthAxis < 0 || lengthAxis > length) || (widthAxis < 0 || widthAxis > width)) {
            return false;
        }

        emergencyExits.add(SeatCoord(lengthAxis, widthAxis));
        return true;
    }

    void clearEmergencyExit() {
        emergencyExits.clearList();
    }

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
            cout << i << " ";
            for (int j = 0; j < passengers.get(i).size(); j++) {
                // Looping through the width
                // cout << setfill(' ') << setw(5) << (round(passengers.get(i).get(j).getMMR() * 1000.0) / 1000.0) << " "; // rounded
                string passStr = (passengers.get(i).get(j).getMMR() == -100.0) ? "EMPTY" : to_string(passengers.get(i).get(j).getMMR());
                cout << setfill(' ') << setw(9) << passStr << " "; // not rounded
            }
            cout << endl;
        }

        cout << "Exit points:" << endl;

        // Prints the exit points
        for (int i = 0; i < emergencyExits.size(); i++) {
            cout << "(" << emergencyExits.get(i).lengthAxis << ", " << emergencyExits.get(i).widthAxis << ")" << endl;
        }
    }

};