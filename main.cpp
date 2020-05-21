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

    Plane p = Plane(24, 6);

    p.addEmergencyExit(0, 0);
    p.addEmergencyExit(0, 5);
    p.addEmergencyExit(23, 0);
    p.addEmergencyExit(23, 5);

    for (int i = 0; i < 30; i++) {
        p.addToPassengers(Passenger::randomPassenger());
    }
    p.addCustomPassenger(Passenger('m', 18, 69.0, 1.8, false, Passenger::NONE));

    p.loadPassengerData("yes.txt");

    p.generate();
    p.printGeneratedPassengers();

    LinkedList<SeatCoord> mySeat = p.getCustomPassengerPos();

    cout << mySeat.get(0).toString() << endl;

    // p.savePassengerData("yes.txt");

    cout << "Program execution complete." << endl;

    return 0;
}