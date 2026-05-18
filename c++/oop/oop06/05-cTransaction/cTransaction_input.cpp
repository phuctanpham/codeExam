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
    cout << "Enter Transaction Date (dd/mm/yyyy): ";
    cin >> transactionDate;
    cout << "Enter Unit Price: ";
    cin >> unitPrice;
    cout << "Enter Area: ";
    cin >> area;
}

void cLandTransaction::input() {
    cout << "\n--- Land Transaction Input ---\n";
    cTransaction::input();
    cout << "Enter Land Type (A/B/C): ";
    cin >> landType;
}

void cTownhouseTransaction::input() {
    cout << "\n--- Townhouse Transaction Input ---\n";
    cTransaction::input();
    cout << "Enter House Type (premium/regular): ";
    cin >> houseType;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
}

void cApartmentTransaction::input() {
    cout << "\n--- Apartment Transaction Input ---\n";
    cTransaction::input();
    cout << "Enter Apartment Code: ";
    cin >> apartmentCode;
    cout << "Enter Floor Position: ";
    cin >> floorPosition;
}

// Operator Overloading applied to input via Polymorphism
istream& operator>>(istream& is, cTransaction& t) {
    t.input(); 
    return is;
}