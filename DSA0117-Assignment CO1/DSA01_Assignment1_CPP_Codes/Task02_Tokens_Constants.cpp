#include <iostream>
using namespace std;

constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

enum class Zone { Inner, Middle, Outer };

int main() {
    Zone selectedZone = Zone::Middle;
    long long fare = 0;

    switch (selectedZone) {
        case Zone::Inner: fare = INNER_FARE_PAISE; break;
        case Zone::Middle: fare = MIDDLE_FARE_PAISE; break;
        case Zone::Outer: fare = OUTER_FARE_PAISE; break;
    }

    bool peak = true;
    if (peak) {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    cout << "Fare in paise: " << fare << '\n';
    cout << "Minimum balance in paise: " << MIN_BALANCE_PAISE << '\n';
    return 0;
}
