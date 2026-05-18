// cTransaction_output.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"
#include <iomanip>

void cTransaction::output() const {
    cout << "Code: " << transactionCode 
         << " | Date: " << transactionDate 
         << " | Area: " << area 
         << " | Price: " << fixed << setprecision(2) << unitPrice;
}

void cLandTransaction::output() const {
    cout << "[LAND] ";
    cTransaction::output();
    cout << " | Type: " << landType 
         << " | Total Cost: " << calculateCost() << endl;
}

void cTownhouseTransaction::output() const {
    cout << "[TOWNHOUSE] ";
    cTransaction::output();
    cout << " | Type: " << houseType 
         << " | Addr: " << address 
         << " | Total Cost: " << calculateCost() << endl;
}

void cApartmentTransaction::output() const {
    cout << "[APARTMENT] ";
    cTransaction::output();
    cout << " | AptCode: " << apartmentCode 
         << " | Floor: " << floorPosition 
         << " | Total Cost: " << calculateCost() << endl;
}

// Operator Overloading applied to output via Polymorphism
ostream& operator<<(ostream& os, const cTransaction& t) {
    t.output(); 
    return os;
}