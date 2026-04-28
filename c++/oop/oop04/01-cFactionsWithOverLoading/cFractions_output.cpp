/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử << cho phép xuất cả dãy
ostream& operator<<(ostream& os, const cFractions& fs) {
    for (int i = 0; i < fs.n; ++i) {
        os << fs.arr[i] << " "; // Tận dụng OVERLOADING << của cFraction
    }
    return os;
}