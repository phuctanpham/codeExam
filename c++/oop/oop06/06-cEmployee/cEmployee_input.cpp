// cEmployee_input.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cEmployee.h"

void cEmployee::input() {
    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, fullName);
    cout << "Enter Date of Birth (dd/mm/yyyy): ";
    cin >> dob;
    // Salary is calculated later, initialized to 0
    salary = 0.0;
}

void cProductionEmployee::input() {
    cout << "\n--- Production Employee Input ---\n";
    cEmployee::input();
    cout << "Enter Base Salary: ";
    cin >> baseSalary;
    cout << "Enter Number of Products: ";
    cin >> numProducts;
}

void cOfficeEmployee::input() {
    cout << "\n--- Office Employee Input ---\n";
    cEmployee::input();
    cout << "Enter Working Days: ";
    cin >> workingDays;
}

// Operator Overloading applied to input via Polymorphism
istream& operator>>(istream& is, cEmployee& emp) {
    emp.input(); 
    return is;
}