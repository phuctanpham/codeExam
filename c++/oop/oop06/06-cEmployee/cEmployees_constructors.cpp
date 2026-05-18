// cEmployees_constructors.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cEmployee.h"

// --- cEmployee Constructors ---
cEmployee::cEmployee() : fullName(""), dob(""), salary(0.0) {}

cEmployee::cEmployee(string name, string dateOfBirth, double sal)
    : fullName(name), dob(dateOfBirth), salary(sal) {}

// --- cProductionEmployee Constructors ---
cProductionEmployee::cProductionEmployee() : cEmployee(), baseSalary(0.0), numProducts(0) {}

cProductionEmployee::cProductionEmployee(string name, string dateOfBirth, double sal, double bSalary, int prods)
    : cEmployee(name, dateOfBirth, sal), baseSalary(bSalary), numProducts(prods) {}

// --- cOfficeEmployee Constructors ---
cOfficeEmployee::cOfficeEmployee() : cEmployee(), workingDays(0) {}

cOfficeEmployee::cOfficeEmployee(string name, string dateOfBirth, double sal, int days)
    : cEmployee(name, dateOfBirth, sal), workingDays(days) {}