#include <iostream>
#include <time.h>
#include "BST.h"
#include "MMRCalculator.h"
#include "PolyFunc.h"
#include "Passenger.h"
#include "Plane.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    srand(time(NULL)); // Random seed for the randomizer

    // TODO:
    /* Make Plane.h:
        In plane object, there is 2 dimensional LinkedList for seating.

        function:
        Plane.reGenerate(): Generates a new seating arrangement based on random Passengers.
        Plane.reGenerate(LinkedList<Passenger>): Generates a new seating arrangement based on random Passengers WITH custom passengers.

    */

    Plane p = Plane(7, 4);
    p.generate();

    Passenger p1 = Passenger('m', 30, 69.0, 160.9, false, Passenger::Disabilities::NONE);
    Passenger p2 = Passenger('m', 30, 69.0, 160.9, false, Passenger::Disabilities::BLIND);

    cout << (p1 < p2) << endl;

    return 0;
}