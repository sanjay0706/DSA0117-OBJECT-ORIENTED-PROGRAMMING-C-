#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double charge(double weightKg,
              bool express = false,
              bool insured = false) {
    double amount = weightKg * 50.0;

    if (express) {
        amount *= 1.5;
    }

    if (insured) {
        amount += 20.0;
    }

    return amount;
}

double charge(int weightGrams) {
    double weightKg = weightGrams / 1000.0;
    return charge(weightKg);
}

double charge(const Parcel& parcel) {
    return charge(parcel.weightKg, parcel.express, parcel.insured);
}

int main() {
    cout << "charge(2) - integer grams: "
         << charge(2) << '\n';

    cout << "charge(2.0) - double kilograms: "
         << charge(2.0) << '\n';

    cout << "charge(2.0f) - float promoted to double: "
         << charge(2.0f) << '\n';

    cout << "charge(2.0, true): "
         << charge(2.0, true) << '\n';

    cout << "charge(2.0, false, true): "
         << charge(2.0, false, true) << '\n';

    Parcel parcel = {2.0, true, true};

    cout << "charge(Parcel): "
         << charge(parcel) << '\n';

    return 0;
}
