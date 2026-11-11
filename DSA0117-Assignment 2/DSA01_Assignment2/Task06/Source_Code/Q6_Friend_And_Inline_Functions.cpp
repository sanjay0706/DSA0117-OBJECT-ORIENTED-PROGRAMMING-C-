#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {
    }

    friend int minutesBetween(const Time& first,
                              const Time& second);

    friend bool earlier(const Time& first,
                        const Time& second);
};

inline int minutesBetween(const Time& first,
                          const Time& second) {
    int firstTotal = first.hours * 60 + first.minutes;
    int secondTotal = second.hours * 60 + second.minutes;

    return abs(firstTotal - secondTotal);
}

inline bool earlier(const Time& first,
                    const Time& second) {
    int firstTotal = first.hours * 60 + first.minutes;
    int secondTotal = second.hours * 60 + second.minutes;

    return firstTotal < secondTotal;
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "Minutes between departure and arrival: "
         << minutesBetween(departure, arrival) << '\n';

    cout << boolalpha;
    cout << "Is arrival earlier than departure? "
         << earlier(arrival, departure) << '\n';

    Time sameTime1(12, 0);
    Time sameTime2(12, 0);

    cout << "Difference for same time: "
         << minutesBetween(sameTime1, sameTime2) << '\n';

    Time beforeNoon(11, 55);
    Time afterNoon(12, 5);

    cout << "Difference across noon: "
         << minutesBetween(beforeNoon, afterNoon) << '\n';

    cout << "Is 11:55 earlier than 12:05? "
         << earlier(beforeNoon, afterNoon) << '\n';

    return 0;
}
