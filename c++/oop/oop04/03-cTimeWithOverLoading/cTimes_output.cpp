/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Overloading << xuat toan bo day thoi diem
ostream& operator<<(ostream& os, const cTimes& ts) {
    for (int i = 0; i < ts.n; ++i)
        os << "[" << ts.arr[i] << "]  ";
    return os;
}
