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

    srand(time(NULL) * (time(NULL) * 0.573238)); // Random seed for the randomizer

    Plane p = Plane(7, 4);

    // p.addEmergencyExit(0, 0);
    // p.addEmergencyExit(0, 3);

    // p.generate();
    // p.printGeneratedPassengers();

    p.printRandomPassengers(20);

    cout << "Program execution complete." << endl;

    return 0;
}