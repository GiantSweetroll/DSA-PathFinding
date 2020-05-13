#include <stdlib.h>
#include <memory>
#include <iostream>
#include <iomanip>
#include "LinkedList.h"
#include "Passenger.h"
#include "BST.h"

#define MIN_AGE 8
#define MAX_AGE 83
#define MIN_WEIGHT 37
#define MAX_WEIGHT 206
#define MIN_HEIGHT 90
#define MAX_HEIGHT 210

using namespace std;

class Plane {

private:

    Passenger you;
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
        If invoked when already generated, regenerate all the passengers. If "you" is filled, then use it.
        */

        // Generates all the random passengers and sort them in the BST.
        BST<Passenger> sortedPassengers = BST<Passenger>();

        for (int i = 0; i < (length * width); i++) {
            Passenger tempPass = Passenger(
                'm',
                ((rand() % (MAX_AGE - MIN_AGE)) + MIN_AGE), // Random age with min 2 and max 85
                ((rand() % (MAX_WEIGHT - MIN_WEIGHT)) + MIN_WEIGHT), // Random weight with min 47 and max 206
                ((rand() % (MAX_HEIGHT - MIN_HEIGHT)) + MIN_HEIGHT), // Random height with min 90 and max 210
                false,
                Passenger::Disabilities::NONE
            );
            sortedPassengers.insert(tempPass);
        }

        // Uncomment to print results for random generation
        // LinkedList<Passenger> sorted = sortedPassengers.returnInOrder();

        // cout << sorted.size() << endl;

        // for (int i = 0; i < sorted.size(); i++) {
        //     Passenger tempPass = sorted.get(i);
        //     cout << "gender: " << tempPass.getGender() << " ";
        //     cout << "age:" << setfill(' ') << setw(5) << tempPass.getAge() << " ";
        //     cout << "weight:" << setfill(' ') << setw(8) << tempPass.getWeight() << " ";
        //     cout << "height:" << setfill(' ') << setw(8) << tempPass.getHeight() << " ";
        //     cout << "MMR:" << setfill(' ') << setw(9) << tempPass.getMMR() << endl;
        // }

        //    for (int i = 0; i < length; i++) {
        //        LinkedList<Passenger> temp = LinkedList<Passenger>();
        //        for (int j = 0; j < width; j++) {
        //            Passenger newPass = Passenger('m', 30, 69.0, 160.9, false, Passenger::Disabilities::NONE);
        //            temp.add(newPass);
        //        }
        //        passengers.add(temp);
        //    }
    }

    void addYou(Passenger you) {
        this->you = you;
    }

};