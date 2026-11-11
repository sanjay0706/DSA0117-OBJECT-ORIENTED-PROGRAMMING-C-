#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int hour;
    long long balance;
    long long farePaise;

    cout << "Enter hour (0-23): ";
    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter an integer from 0 to 23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter card balance in paise: ";
    while (!(cin >> balance) || balance < 0) {
        cout << "Invalid balance. Enter a non-negative amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter fare in paise: ";
    while (!(cin >> farePaise) || farePaise < 0) {
        cout << "Invalid fare. Enter a non-negative amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    bool approved = balance - farePaise >= 5000;

    cout << fixed << setprecision(2);
    cout << "Peak hour: " << boolalpha << peak << '\n';
    cout << "Fare: Rs " << static_cast<double>(farePaise) / 100.0 << '\n';
    if (approved) {
        balance -= farePaise;
        cout << "Journey approved\n";
    } else {
        cout << "Journey denied: minimum balance of Rs 50 must remain\n";
    }
    cout << "Remaining balance: Rs "
         << static_cast<double>(balance) / 100.0 << '\n';
    return 0;
}
