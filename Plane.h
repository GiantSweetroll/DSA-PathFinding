#include <stdlib.h>
#include <memory>
#include <iostream>
#include <iomanip>
#include <limits>
#include <math.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "BST.h"
#include "SeatCoord.h"

#define MIN_AGE 8
#define MAX_AGE 83
#define MIN_WEIGHT 37
#define MAX_WEIGHT 206
#define MIN_HEIGHT 90
#define MAX_HEIGHT 210

using namespace std;

class Plane {

private:

    LinkedList<Passenger> customPassengers;
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

    int clamp(int val, int min, int max) {
        if (val < min) { return min; }
        else if (val > max) { return max; }
        else { return val; }
    }

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

    void generate() {
        /* Generates width * length amount of passenger objects, and puts them in the LinkedList
        If invoked when already generated, regenerate all the passengers. If "you" is filled, then use it.
        */

        passengers.clearList();

        BST<Passenger> sortedPassengers = BST<Passenger>();

        // Adds all the custom passengers to the BST
        for (int i = 0; i < clamp(customPassengers.size(), 0, (length * width)); i++) {
            sortedPassengers.insert(customPassengers.get(i));
        }

        // Generates all the random passengers and sort them in the BST.

        for (int i = 0; i < clamp(((length * width) - customPassengers.size()), 0, (length * width)); i++) {
            Passenger tempPass = Passenger(
                'm',
                ((rand() % (MAX_AGE - MIN_AGE)) + MIN_AGE), // Random age with min 2 and max 85
                ((rand() % (MAX_WEIGHT - MIN_WEIGHT)) + MIN_WEIGHT), // Random weight with min 47 and max 206
                (((rand() % (MAX_HEIGHT - MIN_HEIGHT)) + MIN_HEIGHT) / 100.0), // Random height with min 90 and max 210
                false,
                Passenger::Disabilities::NONE
            );
            sortedPassengers.insert(tempPass);
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
    }

    void addCustomPasengers(Passenger passenger) {
        customPassengers.add(passenger);
    }

    void addCustomPassengers(LinkedList<Passenger> passengers) {
        for (int i = 0; i < passengers.size(); i++) {
            customPassengers.add(passengers.get(i));
        }
    }

    void clearCustomPassengers() {
        customPassengers.clearList();
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
                cout << setfill(' ') << setw(9) << passengers.get(i).get(j).getMMR() << " "; // not rounded
            }
            cout << endl;
        }

        cout << "Exit points:" << endl;

        // Prints the exit points
        for (int i = 0; i < emergencyExits.size(); i++) {
            cout << "(" << emergencyExits.get(i).lengthAxis << ", " << emergencyExits.get(i).widthAxis << ")" << endl;
        }
    }

    void printRandomPassengers(int size) {

        BST<Passenger> sortedPassengers = BST<Passenger>();

        for (int i = 0; i < size; i++) {
            Passenger tempPass = Passenger(
                'm',
                ((rand() % (MAX_AGE - MIN_AGE)) + MIN_AGE), // Random age with min 2 and max 85
                ((rand() % (MAX_WEIGHT - MIN_WEIGHT)) + MIN_WEIGHT), // Random weight with min 47 and max 206
                (((rand() % (MAX_HEIGHT - MIN_HEIGHT)) + MIN_HEIGHT) / 100.0), // Random height with min 90 and max 210
                false,
                Passenger::Disabilities::NONE
            );
            sortedPassengers.insert(tempPass);
        }

        LinkedList<Passenger> sorted = sortedPassengers.returnInOrder();

        cout << sorted.size() << endl;

        for (int i = 0; i < sorted.size(); i++) {
            Passenger tempPass = sorted.get(i);
            cout << "gender: " << tempPass.getGender() << " ";
            cout << "age:" << setfill(' ') << setw(5) << tempPass.getAge() << " ";
            cout << "weight:" << setfill(' ') << setw(8) << tempPass.getWeight() << " ";
            cout << "height:" << setfill(' ') << setw(8) << tempPass.getHeight() << " ";
            cout << "MMR:" << setfill(' ') << setw(9) << tempPass.getMMR() << endl;
        }
    }

};