#pragma once

#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

// Generate a random number.
int randomRangeNum(int min, int max) {
    return ((rand() % (max - min)) + min);
}

int clampNum(int val, int min, int max) {
    if (val < min) { return min; }
    else if (val > max) { return max; }
    else { return val; }
}

// Generate a random number with more precision.
double randomRangeNum(double min, double max) {
    double seeder = (double)rand() / (double)rand();
    return (fmod(((double)rand() + seeder), (max - min)) + min);
}

double randomNormalNum(double min, double max, double multiplier) {
    double val = 0;

    for (int i = 0; i < (int)(ceil(multiplier)); i++) {
        val += randomRangeNum(min, max);
    }

    return val / multiplier;
}
