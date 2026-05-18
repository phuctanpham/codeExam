// cBook_output.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBook.h"
#include <iomanip>

void cBook::output() const {
    cout << "Code: " << bookCode
         << " | Date: " << importDate
         << " | Price: " << fixed << setprecision(2) << unitPrice
         << " | Qty: " << quantity
         << " | Pub: " << publisher;
}

void cTextbook::output() const {
    cout << "[Textbook] ";
    cBook::output();
    cout << " | Condition: " << condition
         << " | Total Cost: " << calculateTotalCost() << endl;
}

void cReferenceBook::output() const {
    cout << "[Ref Book] ";
    cBook::output();
    cout << " | Tax: " << tax
         << " | Total Cost: " << calculateTotalCost() << endl;
}

// Operator Overloading applied to output via Polymorphism
ostream& operator<<(ostream& os, const cBook& b) {
    b.output();
    return os;
}
