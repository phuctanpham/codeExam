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
         << " | Price: " << fixed << setprecision(2) << unitPrice 
         << " | Qty: " << quantity;
}

void cGoldTransaction::output() const {
    cout << "[GOLD] ";
    cTransaction::output();
    cout << " | Type: " << goldType 
         << " | Total Cost: " << calculateCost() << endl;
}

void cCurrencyTransaction::output() const {
    cout << "[CURRENCY] ";
    cTransaction::output();
    cout << " | Currency: " << currencyType 
         << " | Rate: " << exchangeRate 
         << " | Total Cost: " << calculateCost() << endl;
}

// Operator Overloading applied to output via Polymorphism
ostream& operator<<(ostream& os, const cTransaction& t) {
    t.output(); 
    return os;
}