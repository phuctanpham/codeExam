// cTransactions_constructors.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"

// --- cTransaction Constructors ---
cTransaction::cTransaction() : transactionCode(""), transactionDate(""), unitPrice(0.0), area(0.0) {}

cTransaction::cTransaction(string code, string date, double price, double area)
    : transactionCode(code), transactionDate(date), unitPrice(price), area(area) {}

// --- cLandTransaction Constructors ---
cLandTransaction::cLandTransaction() : cTransaction(), landType("A") {}

cLandTransaction::cLandTransaction(string code, string date, double price, double area, string type)
    : cTransaction(code, date, price, area), landType(type) {}

// --- cTownhouseTransaction Constructors ---
cTownhouseTransaction::cTownhouseTransaction() : cTransaction(), houseType("regular"), address("") {}

cTownhouseTransaction::cTownhouseTransaction(string code, string date, double price, double area, string hType, string addr)
    : cTransaction(code, date, price, area), houseType(hType), address(addr) {}

// --- cApartmentTransaction Constructors ---
cApartmentTransaction::cApartmentTransaction() : cTransaction(), apartmentCode(""), floorPosition(0) {}

cApartmentTransaction::cApartmentTransaction(string code, string date, double price, double area, string aCode, int floor)
    : cTransaction(code, date, price, area), apartmentCode(aCode), floorPosition(floor) {}