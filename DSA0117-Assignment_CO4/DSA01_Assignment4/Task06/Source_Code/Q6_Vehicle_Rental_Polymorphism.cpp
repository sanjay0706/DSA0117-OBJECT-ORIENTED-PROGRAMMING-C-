#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string registration;
    double dailyRate;
public:
    Vehicle(const string& reg, double rate)
        : registration(reg), dailyRate(rate) {}
    virtual double rentalCharge(int days) const = 0;
    virtual string type() const = 0;
    virtual void list() const {
        cout << type() << " [" << registration << "] daily rate Rs "
             << dailyRate << '\n';
    }
    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(const string& reg, double rate) : Vehicle(reg, rate) {}
    double rentalCharge(int days) const override { return dailyRate * days; }
    string type() const override { return "Bicycle"; }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDue;
public:
    MotorVehicle(const string& reg, double rate, double fuel, const string& due)
        : Vehicle(reg, rate), fuelLevel(fuel), serviceDue(due) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(const string& reg, double rate, double fuel, const string& due)
        : MotorVehicle(reg, rate, fuel, due) {}
    double rentalCharge(int days) const override { return dailyRate * days; }
    string type() const override { return "Two-wheeler"; }
};

class Car : public MotorVehicle {
protected:
    int seats;
public:
    Car(const string& reg, double rate, double fuel,
        const string& due, int capacity)
        : MotorVehicle(reg, rate, fuel, due), seats(capacity) {}
    double rentalCharge(int days) const override { return dailyRate * days; }
    string type() const override { return "Car"; }
};

class ElectricCar : public Car {
    double batteryKWh;
    double chargePerKWh;
public:
    ElectricCar(const string& reg, double rate, double battery,
                double perKWh, int capacity)
        : Car(reg, rate, 0, "EV service schedule", capacity),
          batteryKWh(battery), chargePerKWh(perKWh) {}
    double rentalCharge(int days) const override {
        return dailyRate * days + batteryKWh * chargePerKWh;
    }
    string type() const override { return "Electric car"; }
};

class ElectricBus : public Vehicle {
    int seats;
    double batteryKWh;
    double chargePerKWh;
public:
    ElectricBus(const string& reg, double rate, int capacity,
                double battery, double perKWh)
        : Vehicle(reg, rate), seats(capacity),
          batteryKWh(battery), chargePerKWh(perKWh) {}
    double rentalCharge(int days) const override {
        return dailyRate * days + batteryKWh * chargePerKWh;
    }
    string type() const override { return "Electric bus"; }
};

class Fleet {
    vector<unique_ptr<Vehicle>> vehicles;
public:
    void add(unique_ptr<Vehicle> vehicle) {
        vehicles.push_back(move(vehicle));
    }
    void list() const {
        cout << "Fleet listing:\n";
        for (const auto& vehicle : vehicles) vehicle->list();
    }
    void rent(size_t index, int days) const {
        if (index >= vehicles.size() || days <= 0) {
            cout << "Rental request rejected\n";
            return;
        }
        cout << vehicles[index]->type() << " rental for " << days
             << " day(s): Rs " << vehicles[index]->rentalCharge(days) << '\n';
    }
    void returnVehicle(size_t index, int daysLate) const {
        if (index >= vehicles.size() || daysLate < 0) {
            cout << "Return rejected\n";
            return;
        }
        double lateFee = daysLate * 200.0;
        cout << vehicles[index]->type() << " returned; late charge: Rs "
             << lateFee << '\n';
    }
};

int main() {
    Fleet fleet;
    fleet.add(make_unique<Bicycle>("BI-101", 100));
    fleet.add(make_unique<TwoWheeler>("TW-202", 300, 75, "2027-03-01"));
    fleet.add(make_unique<Car>("CA-303", 1200, 60, "2027-04-01", 5));
    fleet.add(make_unique<ElectricCar>("EV-404", 1500, 50, 8, 5));
    fleet.add(make_unique<ElectricBus>("EB-505", 4000, 200, 120, 10));

    fleet.list();
    cout << "\nRental demonstrations:\n";
    for (size_t i = 0; i < 5; ++i) fleet.rent(i, 2);
    cout << "\nReturn demonstration:\n";
    fleet.returnVehicle(2, 2);
}
