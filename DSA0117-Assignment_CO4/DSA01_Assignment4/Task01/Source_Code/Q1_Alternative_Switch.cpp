#include <iostream>
using namespace std;
enum class StaffType { Professor, LabAssistant, GuestFaculty };
struct StaffRecord {
    StaffType type;
    double basic;
    double research;
    double hours;
    double rate;
};
double pay(const StaffRecord& s) {
    switch (s.type) {
        case StaffType::Professor: return s.basic * 1.42 + s.research;
        case StaffType::LabAssistant: return s.basic * 1.42;
        case StaffType::GuestFaculty: return s.hours * s.rate;
    }
    return 0;
}
int main() {
    StaffRecord records[] = {
        {StaffType::Professor, 50000, 8000, 0, 0},
        {StaffType::LabAssistant, 30000, 0, 0, 0},
        {StaffType::GuestFaculty, 0, 0, 40, 900}
    };
    for (const auto& record : records) cout << "Pay: Rs " << pay(record) << '\n';
}
