/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử << dùng để xuất phân số
ostream& operator<<(ostream& os, const cFraction& f) {
    if (f.mau == 1) os << f.tu;
    else if (f.tu == 0) os << 0;
    else os << f.tu << "/" << f.mau;
    return os;
}