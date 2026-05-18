// cTransactions_methods.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"
#include <algorithm>  // FIX: added — required for transform and tolower

// Override calculation logic for Gold
double cGoldTransaction::calculateCost() const {
    return quantity * unitPrice;
}

// Override calculation logic for Currency
double cCurrencyTransaction::calculateCost() const {
    // FIX: normalize currencyType to lowercase before comparing
    // so "USD", "usd", "euro", "EURO", "vn", "VN" all work correctly
    string curr = currencyType;
    transform(curr.begin(), curr.end(), curr.begin(), ::tolower);

    if (curr == "usd" || curr == "euro") {
        return quantity * unitPrice * exchangeRate;
    } else if (curr == "vn") {
        return quantity * unitPrice;
    }
    return 0.0;
}
