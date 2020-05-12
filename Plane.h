#include <stdlib.h>
#include <memory>
#include "LinkedList.h"
#include "Passenger.h"

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
       for (int i = 0; i < length; i++) {
           LinkedList<Passenger> temp = LinkedList<Passenger>();
           for (int j = 0; i < width; j++) {
               Passenger newPass = Passenger('m', 30, 69.0, 160.9, false, Passenger::Disabilities::NONE);
               temp.add(newPass);
           }
           passengers.add(temp);
       }
    }

};