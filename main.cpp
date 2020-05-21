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

    p.addEmergencyExit(0, 0);
    p.addEmergencyExit(0, 3);

    for (int i = 0; i < 10; i++) {
        p.addToPassengers(Passenger::randomPassenger());
    }

    p.generate();
    p.printGeneratedPassengers();

    // Passenger::printRandomPassengers(50);

    cout << "Program execution complete." << endl;

    return 0;
}