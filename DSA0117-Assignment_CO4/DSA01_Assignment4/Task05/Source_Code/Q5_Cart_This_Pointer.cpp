#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;
public:
    Cart& add(const string& item, double price) {
        if (n < 10 && price >= 0) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }
    double total() const {
        double sum = 0;
        for (int i = 0; i < n; ++i) sum += prices[i];
        return sum * (100 - discount) / 100;
    }
};
int main() {
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);
    Cart* p = &c;
    p->add("Oil", 180);
    cout << fixed << setprecision(2) << p->total() << '\n';

    Cart direct;
    direct.add("Milk", 40);
    Cart* pointer = &direct;
    pointer->add("Bread", 35);
    Cart& reference = direct;
    reference.add("Eggs", 60);
    Cart* dynamicCart = new Cart;
    dynamicCart->add("Apples", 80);
    cout << "Direct/pointer/reference total: " << direct.total() << '\n';
    cout << "Dynamic object total: " << dynamicCart->total() << '\n';
    delete dynamicCart;

    Cart* carts[] = {&c, &direct};
    Cart* highest = carts[0];
    for (Cart** it = carts; it != carts + 2; ++it)
        if ((*it)->total() > highest->total()) highest = *it;
    cout << "Highest cart total: " << highest->total() << '\n';
}
