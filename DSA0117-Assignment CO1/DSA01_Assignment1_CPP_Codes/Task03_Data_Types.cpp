#include <iostream>
#include <climits>
#include <limits>
using namespace std;

int main() {
    int zoneNumber = 2;
    int hour = 9;
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    long long farePaise = 2000;
    long long cardBalancePaise = 10000;
    long long dailyJourneys = 3000000;
    long long totalCollection = farePaise * dailyJourneys;

    cout << "sizeof(bool): " << sizeof(bool) << " bytes\n";
    cout << "sizeof(char): " << sizeof(char) << " bytes\n";
    cout << "sizeof(int): " << sizeof(int) << " bytes\n";
    cout << "sizeof(long long): " << sizeof(long long) << " bytes\n";
    cout << "sizeof(float): " << sizeof(float) << " bytes\n";
    cout << "sizeof(double): " << sizeof(double) << " bytes\n";
    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "LONG_LONG_MAX: " << LLONG_MAX << '\n';
    cout << "Zone: " << zoneNumber << ", Peak: " << boolalpha << peak << '\n';
    cout << "Balance: " << cardBalancePaise << " paise\n";
    cout << "Collection: " << totalCollection << " paise\n";
    return 0;
}
