
#include "PolyFunc.h"
#pragma once

class Passenger {

public:

    // The enumeration for disabilities.
    enum Disabilities {
    NONE=100,
    HANDICAPPED=50,
    BLIND=30,
    MENTALILLNESS=95,
    MILDSICKNESS=90,
    HEAVYSICKNESS=60,
    MUSCLEATROPHY=40
    };

private:

    // All of the counter functions.
    PolyFunc maleBMI;
    PolyFunc femaleBMI;
    PolyFunc maleAge;
    PolyFunc femaleAge;

    double mmr;

    char gender;
    int age;
    double weight;
    double height;
    bool pregnant;
    Disabilities disabilities;

public:

    Passenger(char gender, int age, double weightKilos, double heightMeters, bool pregnant, Disabilities disabilities) {

        this->gender = gender;
        this->age = age;
        this->weight = weightKilos;
        this->height = heightMeters;
        this->pregnant = pregnant;
        this->disabilities = disabilities;

        double mAge[] = {0.00026693015907715257, -0.00861872554794703, 0.11431569965805355, -0.8031059372543998, 3.208049704700914, -7.25225294980678, 8.560203405248146, -3.055535127157064};
        double fAge[] = {0.00013277564955672591, -0.004259420651991851, 0.05652660579418489, -0.40160119541985706, 1.6469159787971468, -3.904608209985346, 4.956497463635916, -1.5862809978196097};

        double mBMI[] = {-0.0010396607505878297, 0.050036898844165074, 0.40021467028401847};
        double fBMI[] = {-0.0012201516544647953, 0.05844523061769345, 0.3578829726695962};

        maleBMI.changeFunc(mBMI, 3);
        femaleBMI.changeFunc(fBMI, 3);

        maleAge.changeFunc(mAge, 8);
        femaleAge.changeFunc(fAge, 8);

        mmr = 1;

        double BMI = weightKilos / (heightMeters * heightMeters);
        if (gender == 'f') {
            mmr *= femaleBMI.calculate(BMI) * femaleAge.calculate(age/10.0);
        } else if (gender == 'm') {
            mmr *= maleBMI.calculate(BMI) * maleAge.calculate(age/10.0);
        } else {
            mmr = 0;
        }

        mmr *= (pregnant ? 0.75 : 1.0) * (disabilities / 100.0);

    }

    double getMMR() {
        return mmr;
    }

    char getGender() {
        return gender;
    }

    int getAge() {
        return age;
    }

    double getWeight() {
        return weight;
    }

    double getHeight() {
        return height;
    }

    bool isPregnant() {
        return pregnant;
    }

    Disabilities getDisabilities() {
        return disabilities;
    }

};