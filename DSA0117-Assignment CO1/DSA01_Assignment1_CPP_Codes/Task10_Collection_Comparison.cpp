#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const long long farePaise = 1000;
    const long long journeyCounts[] = {20000, 500000, 3000000};

    cout << fixed << setprecision(2);
    for (long long count : journeyCounts) {
        long long integerTotalPaise = farePaise * count;
        double doubleTotalRupees = 10.0 * static_cast<double>(count);

        cout << "Journeys: " << count << '\n';
        cout << "Integer-paise total: " << integerTotalPaise
             << " paise = Rs " << static_cast<double>(integerTotalPaise) / 100.0 << '\n';
        cout << "Double total: Rs " << doubleTotalRupees << '\n';
        cout << "INT_MAX: " << 2147483647 << '\n';
        cout << "Long long total is safe for this test.\n\n";
    }

    int intTotal = 0;
    int fare = 1000;
    int journeys = 3000000;
    // Demonstrates why int is unsuitable: this multiplication exceeds INT_MAX.
    long long safeTotal = static_cast<long long>(fare) * journeys;
    cout << "Safe total using long long: " << safeTotal << " paise\n";
    return 0;
}
