#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    int transactions[10];
    int transactionCount;
    int nextPosition;

    void addTransaction(int amount) {
        transactions[nextPosition] = amount;
        nextPosition = (nextPosition + 1) % 10;

        if (transactionCount < 10) {
            ++transactionCount;
        }
    }

public:
    SavingsAccount(const string& number, double openingBalance)
        : accountNumber(number),
          balance(openingBalance),
          transactions{},
          transactionCount(0),
          nextPosition(0) {
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction(amount);
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction(-amount);
        } else {
            cout << "Withdrawal denied: insufficient balance"
                 << '\n';
        }
    }

    void miniStatement() const {
        cout << "Account number: " << accountNumber << '\n';
        cout << "Mini statement:" << '\n';

        int start = (transactionCount == 10)
                        ? nextPosition
                        : 0;

        for (int i = 0; i < transactionCount; ++i) {
            cout << transactions[(start + i) % 10] << '\n';
        }

        cout << "Available balance: " << balance << '\n';
    }
};

int main() {
    SavingsAccount account("SA1001", 1000.0);

    account.deposit(200);
    account.withdraw(50);
    account.deposit(75);

    account.miniStatement();

    return 0;
}
