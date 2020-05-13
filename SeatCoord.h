#pragma once

struct SeatCoord {

    SeatCoord() {}

    SeatCoord(int lengthAxis, int widthAxis) {
        this->lengthAxis = lengthAxis;
        this->widthAxis = widthAxis;
    }

    int lengthAxis;
    int widthAxis;
};