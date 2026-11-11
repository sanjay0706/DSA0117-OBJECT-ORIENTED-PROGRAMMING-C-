#include <iostream>
#include <array>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr array<long long, 3> FARES = {1000, 2000, 3000};
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_PERCENT = 20;

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour) {
    int index = static_cast<int>(zone);
    if (index < 0 || index >= static_cast<int>(FARES.size())) return -1;

    long long amount = FARES[index];
    if (isPeakHour(hour)) amount += amount * PEAK_PERCENT / 100;
    return amount;
}

class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long initialBalance) : balance(initialBalance) {}

    bool pay(long long fare) {
        if (fare < 0 || balance - fare < MIN_BALANCE_PAISE) return false;
        balance -= fare;
        return true;
    }

    long long getBalance() const { return balance; }
};

int main() {
    SmartCard card(10000);
    long long amount = calculateFare(Zone::Outer, 18);

    if (amount >= 0 && card.pay(amount)) {
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied\n";
    }

    cout << "Fare: " << amount << " paise\n";
    cout << "Balance: " << card.getBalance() << " paise\n";
    cout << "Time per fare lookup: O(1)\n";
    cout << "Space per card: O(1)\n";
    return 0;
}
