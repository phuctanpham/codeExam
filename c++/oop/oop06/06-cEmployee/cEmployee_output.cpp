// cEmployee_output.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cEmployee.h"
#include <iomanip>

void cEmployee::output() const {
    cout << "Name: " << fullName 
         << " | DOB: " << dob 
         << " | Calculated Salary: " << fixed << setprecision(0) << salary;
}

void cProductionEmployee::output() const {
    cout << "[PRODUCTION] ";
    cEmployee::output();
    cout << " | Base: " << baseSalary 
         << " | Products: " << numProducts << endl;
}

void cOfficeEmployee::output() const {
    cout << "[OFFICE] ";
    cEmployee::output();
    cout << " | Days: " << workingDays << endl;
}

// Operator Overloading applied to output via Polymorphism
ostream& operator<<(ostream& os, const cEmployee& emp) {
    emp.output(); 
    return os;
}