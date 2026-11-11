#include <iostream>
using namespace std;

void change(int value, int& reference, int* pointer) {
    value += 10;
    reference += 10;
    *pointer += 10;
}

int& bigger(int& first, int& second) {
    return (first > second) ? first : second;
}

void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

long long applyByReturn(long long fee, int percent) {
    return fee - fee * percent / 100;
}

int main() {
    int a = 1, b = 2, c = 3;

    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    long long hostelFee = 45000;

    applyByValue(hostelFee, 10);
    cout << "After call by value: " << hostelFee << '\n';

    applyByReference(hostelFee, 10);
    cout << "After call by reference: " << hostelFee << '\n';

    cout << "After return by value: "
         << applyByReturn(45000, 10) << '\n';

    return 0;
}
