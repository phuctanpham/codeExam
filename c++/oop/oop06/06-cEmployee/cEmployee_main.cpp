// cEmployee_main.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cEmployee.h"
#include <iomanip>

int main() {
    vector<cEmployee*> employees;
    int numProd, numOffice;

    // 1. Input lists
    cout << "Enter number of Production Employees: ";
    cin >> numProd;
    for (int i = 0; i < numProd; ++i) {
        cEmployee* prod = new cProductionEmployee();
        cin >> *prod; // Polymorphic operator overloading
        employees.push_back(prod);
    }

    cout << "\nEnter number of Office Employees: ";
    cin >> numOffice;
    for (int i = 0; i < numOffice; ++i) {
        cEmployee* off = new cOfficeEmployee();
        cin >> *off;
        employees.push_back(off);
    }

    // 2. Calculate salaries and Total Company Payout
    // FIX: calculateSalary() is now const (pure math), so we explicitly store
    // the result back into the salary field via setSalary() before outputting.
    double totalCompanySalary = 0.0;
    for (auto& emp : employees) {
        double computed = emp->calculateSalary();
        emp->setSalary(computed);          // update salary field for output()
        totalCompanySalary += computed;
    }

    // 3. Output Information
    cout << "\n=== EMPLOYEE LIST & SALARY DETAILS ===\n";
    for (const auto& emp : employees) {
        cout << *emp;
    }

    // 4. Output Total Salary
    cout << "\n=== FINANCIAL SUMMARY ===\n";
    cout << "Total Salary to Pay: " << fixed << setprecision(0) << totalCompanySalary << " VND\n";

    // Memory Cleanup (Lean Philosophy)
    for (auto& emp : employees) {
        delete emp;
    }
    employees.clear();

    return 0;
}
