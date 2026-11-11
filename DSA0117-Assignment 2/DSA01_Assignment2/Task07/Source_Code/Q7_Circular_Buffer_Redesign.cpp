#include <iostream>
using namespace std;

class TransactionHistory {
private:
    static const int CAPACITY = 10;

    int transactions[CAPACITY]{};
    int count;
    int nextPosition;

public:
    TransactionHistory() : count(0), nextPosition(0) {
    }

    void addTransaction(int amount) {
        transactions[nextPosition] = amount;
        nextPosition = (nextPosition + 1) % CAPACITY;

        if (count < CAPACITY) {
            ++count;
        }
    }

    void display() const {
        cout << "Latest transactions:" << '\n';

        int start = (count == CAPACITY) ? nextPosition : 0;

        for (int i = 0; i < count; ++i) {
            cout << transactions[(start + i) % CAPACITY] << '\n';
        }
    }

    int size() const {
        return count;
    }
};

int main() {
    TransactionHistory history;

    for (int i = 1; i <= 12; ++i) {
        history.addTransaction(i * 10);
    }

    history.display();

    cout << "Stored transaction count: "
         << history.size() << '\n';

    cout << "Maximum capacity: 10" << '\n';

    return 0;
}
