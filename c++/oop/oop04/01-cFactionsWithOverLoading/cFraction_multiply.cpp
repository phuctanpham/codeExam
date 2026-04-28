/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử * nhân 2 phân số
cFraction cFraction::operator*(const cFraction& other) {
    return cFraction(tu * other.tu, mau * other.mau);
}