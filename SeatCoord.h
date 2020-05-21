#include <string>
#pragma once

struct SeatCoord {
    // (length, width)

    SeatCoord() {}

    SeatCoord(int lengthAxis, int widthAxis) {
        this->lengthAxis = lengthAxis;
        this->widthAxis = widthAxis;
    }

    string toString() {
        return ("(" + to_string(lengthAxis) + ", " + to_string(widthAxis) + ")");
    }

    int lengthAxis;
    int widthAxis;
};