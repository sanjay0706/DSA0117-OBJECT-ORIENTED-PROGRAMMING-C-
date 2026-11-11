#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;

    double c = a / b;
    double d = static_cast<double>(a) / b;

    cout << c << ' ' << d << '\n';

    char ch = 'A' + 2;
    cout << ch << ' ' << ch + 1 << '\n';

    bool flag = 5;
    cout << flag << ' ' << boolalpha << flag << '\n';

    unsigned int u = 1;
    int s = -1;
    cout << (s < u ? "s < u" : "s >= u") << '\n';

    // Safer explicit conversions:
    double exactDivision = static_cast<double>(a) / static_cast<double>(b);
    int wholeNumber{3};
    cout << "Explicit division: " << exactDivision << '\n';
    cout << "Brace-initialized integer: " << wholeNumber << '\n';
    return 0;
}
