#include "PolyFunc.h"

#pragma once

class MMRCalculator {

private:

    PolyFunc maleBMI;
    PolyFunc femaleBMI;
    PolyFunc maleAge;
    PolyFunc femaleAge;

public:

    MMRCalculator() {
        double mAge[] = {0.00026693015907715257, -0.00861872554794703, 0.11431569965805355, -0.8031059372543998, 3.208049704700914, -7.25225294980678, 8.560203405248146, -3.055535127157064};
        double fAge[] = {0.00013277564955672591, -0.004259420651991851, 0.05652660579418489, -0.40160119541985706, 1.6469159787971468, -3.904608209985346, 4.956497463635916, -1.5862809978196097};

        double mBMI[] = {-0.0010396607505878297, 0.050036898844165074, 0.40021467028401847};
        double fBMI[] = {-0.0012201516544647953, 0.05844523061769345, 0.3578829726695962};

        maleBMI.changeFunc(mBMI, 3);
        femaleBMI.changeFunc(fBMI, 3);

        maleAge.changeFunc(mAge, 8);
        femaleAge.changeFunc(fAge, 8);
    }

    double calculateMMR(char gender, int age, double weightKilos, double heightMeters) {

        double points = 1;

        double BMI = weightKilos / (heightMeters * heightMeters);
        if (gender == 'f') {
            points *= femaleBMI.calculate(BMI) * femaleAge.calculate(age/10.0);
        } else {
            points *= maleBMI.calculate(BMI) * maleAge.calculate(age/10.0);
        }

        return points;

    }

};