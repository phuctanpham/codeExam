/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử >> dùng để nhập phân số
istream& operator>>(istream& is, cFraction& f) {
    is >> f.tu >> f.mau;
    if (f.mau == 0) f.mau = 1;
    f.simplify();
    return is;
}