#include "LinkedList.h"
#include <math.h>

#pragma once

// This class is to store a one variable mathematical polynomial function, then use it to calculate the value of f(x).
class PolyFunc {

private:

    // This is to store the functions
    LinkedList<double> func;

public:

    // Convert into linkedlist
    PolyFunc() {}
    PolyFunc(double vars[], int arrSize) {
        for (int i = 0; i < arrSize; i++) {
            func.add(vars[i]);
        }
    }

    ~PolyFunc() {}


    // Functions

    // Calculate
    double calculate(double x) {
        double result = 0;
        for (int i = 0; i < func.size(); i++) {
            result += func.get(i) * pow(x, func.size() - i - 1);
        }
        return result;
    }

    void changeFunc(double vars[], int arrSize) {
        func.clearList();
        for (int i = 0; i < arrSize; i++) {
            func.add(vars[i]);
        }
    }

};