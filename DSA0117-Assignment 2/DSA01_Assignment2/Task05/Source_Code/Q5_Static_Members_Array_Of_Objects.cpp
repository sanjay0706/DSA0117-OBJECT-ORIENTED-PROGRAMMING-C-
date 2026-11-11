#include <iostream>
#include <string>
using namespace std;

class Token {
private:
    static int next;
    int id;

public:
    Token() {
        id = ++next;
    }

    int get() const {
        return id;
    }

    static int issued() {
        return next - 100;
    }
};

int Token::next = 100;

class BusTicket {
private:
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string passengerName;

public:
    explicit BusTicket(const string& name)
        : seat(0), passengerName(name) {
        if (issued < CAPACITY) {
            seat = ++issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        if (seat != 0) {
            cout << passengerName << ": Seat " << seat << '\n';
        } else {
            cout << passengerName << ": Waiting" << '\n';
        }
    }
};

int BusTicket::issued = 0;

int main() {
    Token counter[3];
    Token extra;

    cout << "Token IDs: "
         << counter[0].get() << ' '
         << counter[2].get() << ' '
         << extra.get() << '\n';

    cout << "Tokens issued: " << Token::issued() << '\n';

    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    cout << "\nBus ticket allocation:" << '\n';

    for (const BusTicket& ticket : trip) {
        ticket.print();
    }

    cout << "Seats issued: " << BusTicket::count() << '\n';

    return 0;
}
