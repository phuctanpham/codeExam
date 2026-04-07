/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

#include <algorithm>

using namespace std;

namespace {
bool isLessFraction(const cFraction& left, const cFraction& right) {
    return static_cast<long long>(left.getNumerator()) * right.getDenominator()
         < static_cast<long long>(right.getNumerator()) * left.getDenominator();
}
}

void cFractions::sortAscending() {
    sort(fractions.begin(), fractions.end(), isLessFraction);
}