/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// OVERLOADING toan tu << de in toan bo mang
ostream& operator<<(ostream& os, const cDates& ds) {
    for (int i = 0; i < ds.n; ++i) {
        os << "[" << ds.arr[i] << "]  ";
    }
    return os;
}