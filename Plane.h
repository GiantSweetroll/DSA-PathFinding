#include "LinkedList.h"
#include "Passenger.h"

class Plane {

private:

    LinkedList<LinkedList<Passenger>> passengers;

public:

    Plane() {} // Constructor to fill the plane
    ~Plane() {} // Constructor to delete the object

};