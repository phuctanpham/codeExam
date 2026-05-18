// cTransactions_methods.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"

// Override calculation logic for Land
double cLandTransaction::calculateCost() const {
    if (landType == "A") {
        return area * unitPrice * 1.5;
    }
    // Type "B" or "C"
    return area * unitPrice;
}

// Override calculation logic for Townhouse
double cTownhouseTransaction::calculateCost() const {
    if (houseType == "regular") {
        return area * unitPrice * 0.9;
    }
    // "premium"
    return area * unitPrice;
}

// Override calculation logic for Apartment
double cApartmentTransaction::calculateCost() const {
    if (floorPosition == 1) {
        return area * unitPrice * 2.0;
    } else if (floorPosition >= 15) {
        return area * unitPrice * 1.2;
    }
    // Remaining floors
    return area * unitPrice;
}