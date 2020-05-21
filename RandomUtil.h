#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

// Generate a random number.
int randomRange(int min, int max) {
    return ((rand() % (max - min)) + min);
}

// Generate a random number with more precision.
double randomRange(double min, double max) {
    double seeder = (double)rand() / (double)rand();
    return (fmod(((double)rand() + seeder), (max - min)) + min);
}

double randomNormal(double min, double max, double multiplier) {
    double val = 0;

    for (int i = 0; i < (int)(ceil(multiplier)); i++) {
        val += randomRange(min, max);
    }

    return val / multiplier;
}