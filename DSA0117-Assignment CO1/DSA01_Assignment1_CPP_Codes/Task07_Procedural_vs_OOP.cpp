#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

// Procedural approach
bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}

bool proceduralDeduct(long long& balance, long long fare) {
    if (!proceduralCanTravel(balance, fare)) return false;
    balance -= fare;
    return true;
}

// Object-oriented approach
class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}

    bool canTravel(long long fare) const {
        return fare >= 0 && balancePaise - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }

    long long getBalance() const {
        return balancePaise;
    }
};

int main() {
    long long proceduralBalance = 10000;
    cout << "Procedural journey: "
         << (proceduralDeduct(proceduralBalance, 3000) ? "Approved" : "Denied")
         << ", balance = " << proceduralBalance << " paise\n";

    SmartCard card(10000);
    cout << "OOP journey: "
         << (card.deduct(3000) ? "Approved" : "Denied")
         << ", balance = " << card.getBalance() << " paise\n";
    return 0;
}
