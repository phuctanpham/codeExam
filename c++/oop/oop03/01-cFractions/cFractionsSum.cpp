/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

using namespace std;

cFraction cFractions::sum() const {
    cFraction result;

    for (const cFraction& fraction : fractions) {
        result = cFraction(
            result.getNumerator() * fraction.getDenominator() + fraction.getNumerator() * result.getDenominator(),
            result.getDenominator() * fraction.getDenominator()
        );
    }

    return result;
}