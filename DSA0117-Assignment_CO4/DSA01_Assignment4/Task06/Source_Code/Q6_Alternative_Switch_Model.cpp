#include <iostream>
using namespace std;
enum class Kind { Bicycle, TwoWheeler, Car, ElectricCar };
struct VehicleRecord {
    Kind kind;
    double dailyRate;
    double batteryKWh;
    double pricePerKWh;
};
double charge(const VehicleRecord& v, int days) {
    switch (v.kind) {
        case Kind::Bicycle:
        case Kind::TwoWheeler:
        case Kind::Car: return v.dailyRate * days;
        case Kind::ElectricCar:
            return v.dailyRate * days + v.batteryKWh * v.pricePerKWh;
    }
    return 0;
}
int main() {
    VehicleRecord fleet[] = {
        {Kind::Bicycle, 100, 0, 0},
        {Kind::TwoWheeler, 300, 0, 0},
        {Kind::Car, 1200, 0, 0},
        {Kind::ElectricCar, 1500, 50, 8}
    };
    for (const auto& v : fleet) cout << "Charge: Rs " << charge(v, 2) << '\n';
}
