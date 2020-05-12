#include <stdlib.h>
#include <memory>
#include <iostream>
#include "LinkedList.h"
#include "Passenger.h"

using namespace std;

class Plane {

private:

    LinkedList<LinkedList<Passenger>> passengers;
    int length;
    int width;

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
        If invoked when already generated, regenerate all the passengers.
        */

        // Generates all the random passengers in a linked list
        LinkedList<Passenger> randomPassengers = LinkedList<Passenger>();

        for (int i = 0; i < (length * width); i++) {
            Passenger tempPass = Passenger(
                'm',
                ((rand() % 93) + 2), // Random age with min 2 and max 94
                (rand() % 160 + 47.0), // Random age with min 47 and max 206
                (rand() % 120 + 90.0), // Random age with min 90 and max 210
                false,
                Passenger::Disabilities::NONE
            );
            randomPassengers.add(tempPass);
        }

    //    for (int i = 0; i < length; i++) {
    //        LinkedList<Passenger> temp = LinkedList<Passenger>();
    //        for (int j = 0; j < width; j++) {
    //            Passenger newPass = Passenger('m', 30, 69.0, 160.9, false, Passenger::Disabilities::NONE);
    //            temp.add(newPass);
    //        }
    //        passengers.add(temp);
    //    }
    }

};