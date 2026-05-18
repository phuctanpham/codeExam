// cTransaction_input.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"

void cTransaction::input() {
    cout << "Enter Transaction Code: ";
    cin >> transactionCode;
    cout << "Enter Transaction Date: ";
    cin >> transactionDate;
    cout << "Enter Unit Price: ";
    cin >> unitPrice;
    cout << "Enter Quantity: ";
    cin >> quantity;
}

void cGoldTransaction::input() {
    cout << "\n--- Gold Transaction Input ---\n";
    cTransaction::input();
    cin.ignore();
    cout << "Enter Gold Type: ";
    getline(cin, goldType);
}

void cCurrencyTransaction::input() {
    cout << "\n--- Currency Transaction Input ---\n";
    cTransaction::input();
    cout << "Enter Exchange Rate (1 for VN): ";
    cin >> exchangeRate;
    cin.ignore();
    cout << "Enter Currency Type (VN, USD, Euro): ";
    getline(cin, currencyType);
}

// Operator Overloading applied to input via Polymorphism
istream& operator>>(istream& is, cTransaction& t) {
    t.input(); 
    return is;
}