// cEmployees_methods.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cEmployee.h"

// Override salary calculation logic for Production Employee
// FIX: now const — only computes and returns; salary field updated in main() via setSalary()
double cProductionEmployee::calculateSalary() const {
    return baseSalary + (numProducts * 5000.0);
}

// Override salary calculation logic for Office Employee
// FIX: now const — only computes and returns; salary field updated in main() via setSalary()
double cOfficeEmployee::calculateSalary() const {
    return workingDays * 100000.0;
}
