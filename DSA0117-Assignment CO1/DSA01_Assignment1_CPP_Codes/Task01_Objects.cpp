#include <iostream>
#include <string>
using namespace std;

class SmartCard {
private:
    long long balancePaise;

public:
    SmartCard(long long initialBalance) : balancePaise(initialBalance) {}

    long long getBalance() const {
        return balancePaise;
    }

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 && balancePaise - farePaise >= 5000;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) return false;
        balancePaise -= farePaise;
        return true;
    }
};

enum class Zone { Inner, Middle, Outer };

class Journey {
private:
    Zone zone;
    bool peak;

public:
    Journey(Zone z, bool isPeak) : zone(z), peak(isPeak) {}

    Zone getZone() const { return zone; }
    bool isPeak() const { return peak; }
};

class FareTable {
public:
    static long long calculate(Zone zone, bool peak) {
        long long amount = 0;
        switch (zone) {
            case Zone::Inner: amount = 1000; break;
            case Zone::Middle: amount = 2000; break;
            case Zone::Outer: amount = 3000; break;
        }
        if (peak) amount += amount * 20 / 100;
        return amount;
    }
};

int main() {
    SmartCard card(10000);
    Journey journey(Zone::Outer, true);
    long long fare = FareTable::calculate(journey.getZone(), journey.isPeak());

    if (card.deduct(fare)) {
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied\n";
    }
    cout << "Remaining balance: Rs " << card.getBalance() / 100
         << "." << (card.getBalance() % 100 < 10 ? "0" : "")
         << card.getBalance() % 100 << '\n';
    return 0;
}
