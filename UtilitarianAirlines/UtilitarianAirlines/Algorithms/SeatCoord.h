#include <string>
#pragma once

struct SeatCoord {
    // (length, width)

    SeatCoord() {}

    SeatCoord(double lengthAxis, double widthAxis) {
        this->lengthAxis = lengthAxis;
        this->widthAxis = widthAxis;
    }

    string toString() {
        return ("(" + to_string(lengthAxis) + ", " + to_string(widthAxis) + ")");
    }

    double lengthAxis;
    double widthAxis;
};