// cBooks_constructors.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBook.h"

// --- cBook Constructors ---
cBook::cBook() : bookCode(""), importDate(""), unitPrice(0.0), quantity(0), publisher("") {}

cBook::cBook(string code, string date, double price, int qty, string pub)
    : bookCode(code), importDate(date), unitPrice(price), quantity(qty), publisher(pub) {}

// --- cTextbook Constructors ---
cTextbook::cTextbook() : cBook(), condition("new") {}

cTextbook::cTextbook(string code, string date, double price, int qty, string pub, string cond)
    : cBook(code, date, price, qty, pub), condition(cond) {}

// --- cReferenceBook Constructors ---
cReferenceBook::cReferenceBook() : cBook(), tax(0.0) {}

cReferenceBook::cReferenceBook(string code, string date, double price, int qty, string pub, double taxRate)
    : cBook(code, date, price, qty, pub), tax(taxRate) {}