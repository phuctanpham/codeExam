/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

using namespace std;

namespace {
bool isLessFraction(const cFraction& left, const cFraction& right) {
    return static_cast<long long>(left.getNumerator()) * right.getDenominator()
         < static_cast<long long>(right.getNumerator()) * left.getDenominator();
}
}

cFraction cFractions::findMax() const {
    if (fractions.empty()) {
        return cFraction();
    }

    cFraction maxFraction = fractions[0];

    for (size_t i = 1; i < fractions.size(); ++i) {
        if (isLessFraction(maxFraction, fractions[i])) {
            maxFraction = fractions[i];
        }
    }

    return maxFraction;
}