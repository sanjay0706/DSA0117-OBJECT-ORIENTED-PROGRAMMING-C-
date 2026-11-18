#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;
public:
    Staff(const string& n, int staffId, double pay)
        : name(n), id(staffId), basic(pay) {}
    virtual double pay() const = 0;
    virtual void display() const {
        cout << name << " (ID " << id << ") pay: Rs " << pay() << '\n';
    }
    virtual ~Staff() = default;
};

class Professor : public Staff {
    double researchAllowance;
public:
    Professor(const string& n, int id, double basic, double research)
        : Staff(n, id, basic), researchAllowance(research) {}
    double pay() const override { return basic * 1.42 + researchAllowance; }
};

class LabAssistant : public Staff {
public:
    LabAssistant(const string& n, int id, double basic)
        : Staff(n, id, basic) {}
    double pay() const override { return basic * 1.42; }
};

class GuestFaculty : public Staff {
    double hours, rate;
public:
    GuestFaculty(const string& n, int id, double h, double r)
        : Staff(n, id, 0), hours(h), rate(r) {}
    double pay() const override { return hours * rate; }
};

int main() {
    vector<unique_ptr<Staff>> staff;
    staff.push_back(make_unique<Professor>("Anita", 101, 50000, 8000));
    staff.push_back(make_unique<LabAssistant>("Bala", 102, 30000));
    staff.push_back(make_unique<GuestFaculty>("Charan", 103, 40, 900));

    cout << "College Payroll\n";
    for (const auto& person : staff) person->display();
}
