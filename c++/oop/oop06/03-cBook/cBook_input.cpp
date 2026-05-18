// cBook_input.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBook.h"

void cBook::input() {
    cout << "Enter Book Code: ";
    cin >> bookCode;
    cout << "Enter Import Date: ";
    cin >> importDate;
    cout << "Enter Unit Price: ";
    cin >> unitPrice;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cin.ignore();
    cout << "Enter Publisher: ";
    getline(cin, publisher);
}

void cTextbook::input() {
    cout << "\n--- Textbook Input ---\n";
    cBook::input();
    cout << "Enter Condition (new/old): ";
    cin >> condition;
}

void cReferenceBook::input() {
    cout << "\n--- Reference Book Input ---\n";
    cBook::input();
    cout << "Enter Tax amount: ";
    cin >> tax;
}

// Operator Overloading applied to input via Polymorphism
istream& operator>>(istream& is, cBook& b) {
    b.input(); 
    return is;
}