#pragma once
#include <iomanip>
#include "PolyFunc.h"
#include "RandomUtil.h"
#include "BST.h"

#define MIN_AGE 8
#define MAX_AGE 83
#define MIN_WEIGHT 37
#define MAX_WEIGHT 206
#define MIN_HEIGHT 90
#define MAX_HEIGHT 210

class Passenger {

public:

    // The enumeration for disabilities.
    enum Disabilities {
        NONE = 100,
        HANDICAPPED = 50,
        BLIND = 30,
        MENTALILLNESS = 90,
        MILDSICKNESS = 95,
        HEAVYSICKNESS = 60,
        MUSCLEATROPHY = 40
    };

    enum Gender {
        MALE,
        FEMALE,
        OTHER
    };

    static const int disabilitiesCount = 7;

private:

    double mmr;

    Gender gender;
    int age;
    double weight;
    double height;
    bool pregnant;
    Disabilities disabilities;

    static Disabilities randomDisable() {
        // 1 every 100 people has a disability, and its' randomized.
        int rando = rand();
        if (rando % 100 == 0) {
            Disabilities disableArr[] = {HANDICAPPED, BLIND, MENTALILLNESS, HEAVYSICKNESS, MUSCLEATROPHY};
            return disableArr[rand() % 5];
        } else if (rando % 100 >= 95) {
            // 5 every 100 people is mildly sick.
            return MILDSICKNESS;
        } else {
            return NONE;
        }
    }

public:

    // Static function to generate a random passenger based on normal distribution
    static Passenger randomPassenger() {
        Gender gender = ((rand() % 2) == 1) ? MALE : FEMALE;
        // Note that the parameters in the randomNormal function Defines the upper bound and lower bound of the distribution.
        return Passenger(
                gender,
                (clamp(randomNormal(0.0, 75.0, 3.0), MIN_AGE, MAX_AGE)), // Random age with min 2 and max 8
                (clamp(randomNormal(30.0, 110.0, 5.0), MIN_WEIGHT, MAX_WEIGHT)), // Random weight with min 47 and max 206
                (clamp(randomNormal(120.0, 225.0, 4.0), MIN_HEIGHT, MAX_HEIGHT) / 100.0), // Random height with min 90 and max 210
                ((gender == FEMALE) && (rand() % 100 == 3)) ? true : false, // 3 out of 100 females are pregnant.
                randomDisable()
            );
    }

    static void printRandomPassengers(int size) {

        BST<Passenger> sortedPassengers = BST<Passenger>();

        for (int i = 0; i < size; i++) {
            Passenger tempPass = Passenger::randomPassenger();
            sortedPassengers.insert(tempPass);
        }

        LinkedList<Passenger> sorted = sortedPassengers.returnInOrder();

        cout << sorted.size() << endl;

        for (int i = 0; i < sorted.size(); i++) {
            Passenger tempPass = sorted.get(i);
            cout << "gender: " << tempPass.getGender() << " ";
            cout << "age:" << setfill(' ') << setw(5) << tempPass.getAge() << " ";
            cout << "weight:" << setfill(' ') << setw(5) << tempPass.getWeight() << " ";
            cout << "height:" << setfill(' ') << setw(7) << tempPass.getHeight() << " ";
            cout << "MMR:" << setfill(' ') << setw(9) << tempPass.getMMR() << " ";
            cout << "Preg:" << setfill(' ') << setw(3) << tempPass.isPregnant() << " ";
            cout << "Disable:" << setfill(' ') << setw(5) << tempPass.getDisabilities() << endl;
        }
    }

    static Passenger generateEmpty() {
        return Passenger();
    }

    Passenger() { mmr = -100.0; } // Empty passenger mmr

    Passenger(Gender gender, int age, double weightKilos, double heightMeters, bool pregnant, Disabilities disabilities) {

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

        PolyFunc maleBMI(mBMI, 3);
        PolyFunc femaleBMI(fBMI, 3);

        PolyFunc maleAge(mAge, 8);
        PolyFunc femaleAge(fAge, 8);

        mmr = 1;

        double BMI = weightKilos / (heightMeters * heightMeters);
        if (gender == FEMALE) {
            mmr *= femaleBMI.calculate(BMI) * femaleAge.calculate(age/10.0);
        } else if (gender == MALE) {
            mmr *= maleBMI.calculate(BMI) * maleAge.calculate(age/10.0);
        } else {
            mmr = 0;
        }

        mmr *= ((gender == FEMALE && pregnant) ? 0.75 : 1.0) * (disabilities / 100.0);

    }

    double getMMR() {
        return mmr;
    }

    Gender getGender() {
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

    // This method detects whether the passenger is an "empty" passenger
    bool isEmpty() {
	if (mmr == -100.0) {
		return true;
	}
	return false;
    }
    
    // Custom methods

    // TODO: Overload < and > operators.

    bool operator < (const Passenger right) {
        return (this->mmr < right.mmr);
    }

    bool operator > (const Passenger right) {
        return (this->mmr > right.mmr);
    }

    bool operator <= (const Passenger right) {
        return (this->mmr <= right.mmr);
    }

    bool operator >= (const Passenger right) {
        return (this->mmr >= right.mmr);
    }

    bool operator == (const Passenger right) {
        return (this->mmr == right.mmr);
    }

};
