#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class Zone { Inner, Middle, Outer, Invalid };

long long calculateFare(Zone zone, int hour) {
    long long base = 0;
    switch (zone) {
        case Zone::Inner: base = 1000; break;
        case Zone::Middle: base = 2000; break;
        case Zone::Outer: base = 3000; break;
        default: return -1;
    }

    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    if (peak) base += base * 20 / 100;
    return base;
}

int main() {
    struct Test {
        string name;
        Zone zone;
        int hour;
        long long expected;
    };

    vector<Test> tests = {
        {"Inner off-peak", Zone::Inner, 11, 1000},
        {"Middle peak at 8", Zone::Middle, 8, 2400},
        {"Outer at 10", Zone::Outer, 10, 3000},
        {"Inner peak at 17", Zone::Inner, 17, 1200},
        {"Outer at 20", Zone::Outer, 20, 3000},
        {"Invalid zone", Zone::Invalid, 12, -1}
    };

    int passed = 0;
    for (const Test& test : tests) {
        long long actual = calculateFare(test.zone, test.hour);
        bool ok = (actual == test.expected);
        if (ok) ++passed;

        cout << test.name << " | expected: " << test.expected
             << " | actual: " << actual
             << " | " << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "Passed " << passed << " of " << tests.size() << " tests\n";

    long long balance = 6000;
    long long fare = 1000;
    cout << "Exactly Rs 50 remains: "
         << boolalpha << (balance - fare == 5000) << '\n';
    return 0;
}
