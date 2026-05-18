// cBooks_methods.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBook.h"
#include <algorithm>  // FIX: added — required for transform and tolower

// Override calculation logic for Textbook
double cTextbook::calculateTotalCost() const {
    // FIX: normalize condition to lowercase before comparing
    // so "New", "NEW", "new" all work correctly
    string cond = condition;
    transform(cond.begin(), cond.end(), cond.begin(), ::tolower);

    if (cond == "new") {
        return quantity * unitPrice;
    } else if (cond == "old") {
        return quantity * unitPrice * 0.5;
    }
    return 0.0;
}

// Override calculation logic for Reference Book
double cReferenceBook::calculateTotalCost() const {
    return (quantity * unitPrice) + tax;
}
