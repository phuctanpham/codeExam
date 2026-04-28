/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử - trừ 2 phân số
cFraction cFraction::operator-(const cFraction& other) {
    int t = tu * other.mau - other.tu * mau;
    int m = mau * other.mau;
    return cFraction(t, m);
}