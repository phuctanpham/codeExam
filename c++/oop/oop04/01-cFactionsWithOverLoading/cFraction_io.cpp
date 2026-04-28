/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử >> để nhập liệu chuẩn
istream& operator>>(istream& is, cFraction& f) {
    is >> f.tu >> f.mau;
    if (f.mau == 0) f.mau = 1;
    f.rutGon();
    return is;
}

// OVERLOADING toán tử << để in dữ liệu
ostream& operator<<(ostream& os, const cFraction& f) {
    if (f.mau == 1) os << f.tu;
    else os << f.tu << "/" << f.mau;
    return os;
}