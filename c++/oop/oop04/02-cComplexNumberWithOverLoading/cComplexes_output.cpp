/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

// OVERLOADING toan tu << xuat day so phuc
ostream& operator<<(ostream& os, const cComplexes& cs) {
    for (int i = 0; i < cs.n; ++i) {
        os << "[" << cs.arr[i] << "]  ";
    }
    return os;
}