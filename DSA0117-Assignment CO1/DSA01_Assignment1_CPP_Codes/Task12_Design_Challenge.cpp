#include <iostream>
#include <array>
#include <vector>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };

constexpr array<long long, 4> FARES_PAISE = {
    1000, 2000, 3000, 6000
};
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;

class MonthlyPass {
private:
    Zone firstZone;
    Zone secondZone;

public:
    MonthlyPass(Zone a, Zone b) : firstZone(a), secondZone(b) {}

    bool covers(Zone zone) const {
        return zone == firstZone || zone == secondZone;
    }
};

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long initialBalance)
        : balancePaise(initialBalance) {}

    bool pay(long long amount) {
        if (amount < 0 || balancePaise - amount < MIN_BALANCE_PAISE)
            return false;
        balancePaise -= amount;
        return true;
    }

    long long getBalance() const { return balancePaise; }
};

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour, bool weekend,
                        const MonthlyPass& pass) {
    int index = static_cast<int>(zone);
    if (index < 0 || index >= static_cast<int>(FARES_PAISE.size()))
        return -1;

    // A valid monthly pass covers the journey without an additional fare.
    if (pass.covers(zone)) return 0;

    long long amount = FARES_PAISE[index];

    // Weekend discount and peak surcharge do not combine.
    if (weekend) {
        amount -= amount * WEEKEND_DISCOUNT_PERCENT / 100;
    } else if (isPeakHour(hour)) {
        amount += amount * PEAK_PERCENT / 100;
    }

    return amount;
}

int main() {
    SmartCard card(20000); // Rs 200
    MonthlyPass pass(Zone::Inner, Zone::Middle);

    struct Journey {
        Zone zone;
        int hour;
        bool weekend;
    };

    vector<Journey> journeys = {
        {Zone::Inner, 9, false},     // covered by pass: free
        {Zone::Outer, 9, false},     // peak: Rs 36
        {Zone::Airport, 12, true},   // weekend: Rs 54
        {Zone::Airport, 18, false}   // peak: Rs 72
    };

    for (const Journey& journey : journeys) {
        long long amount = calculateFare(
            journey.zone, journey.hour, journey.weekend, pass
        );

        if (amount < 0) {
            cout << "Invalid zone\n";
        } else if (card.pay(amount)) {
            cout << "Approved; fare = Rs "
                 << amount / 100 << "."
                 << (amount % 100 < 10 ? "0" : "")
                 << amount % 100 << '\n';
        } else {
            cout << "Denied: minimum balance requirement not satisfied\n";
        }

        cout << "Balance = Rs " << card.getBalance() / 100 << "."
             << (card.getBalance() % 100 < 10 ? "0" : "")
             << card.getBalance() % 100 << "\n\n";
    }

    return 0;
}
