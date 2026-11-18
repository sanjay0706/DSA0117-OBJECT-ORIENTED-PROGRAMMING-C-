#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int id;
    string phone;
public:
    Person(const string& n, int i, const string& p)
        : name(n), id(i), phone(p) { cout << "Person "; }
    virtual ~Person() = default;
};
class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
public:
    Student(const string& n, int i, const string& p,
            const string& course, double gpa)
        : Person(n, i, p), programme(course), cgpa(gpa) {
        cout << "Student ";
    }
};
class Staff : virtual public Person {
protected:
    string department;
    double salary;
public:
    Staff(const string& n, int i, const string& p,
          const string& dept, double pay)
        : Person(n, i, p), department(dept), salary(pay) {
        cout << "Staff ";
    }
};
class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(const string& n, int i, const string& p,
                      const string& course, double gpa,
                      const string& dept, double pay)
        : Person(n, i, p), Student(n, i, p, course, gpa),
          Staff(n, i, p, dept, pay) {
        cout << "TA ";
    }
    void display() const {
        cout << "\nName: " << name << "\nID: " << id
             << "\nProgramme: " << programme << "\nCGPA: " << cgpa
             << "\nDepartment: " << department << "\nSalary: " << salary << '\n';
    }
};
class ResearchScholar : public Student {
    double fellowship;
public:
    ResearchScholar(const string& n, int i, const string& p,
                    const string& course, double gpa, double f)
        : Person(n, i, p), Student(n, i, p, course, gpa), fellowship(f) {}
};
int main() {
    TeachingAssistant ta("Kavya", 101, "9876543210", "AI&DS", 9.1,
                         "Computer Science", 25000);
    ta.display();
}
