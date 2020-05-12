#include <iostream>
#include <memory>
#include "BST.h"
#include "MMRCalculator.h"
#include "PolyFunc.h"
#include "Passenger.h"
#include "Plane.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    // TODO:
    /* Make Plane.h:
        In plane object, there is 2 dimensional LinkedList for seating.

        function:
        Plane.reGenerate(): Generates a new seating arrangement based on random Passengers.
        Plane.reGenerate(LinkedList<Passenger>): Generates a new seating arrangement based on random Passengers WITH custom passengers.

    */

   Plane p = Plane(7, 4);
   p.generate();

    return 0;
}