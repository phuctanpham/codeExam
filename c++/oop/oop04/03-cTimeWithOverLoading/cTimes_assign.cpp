/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Overloading operator= - Deep Copy, chong tu gan (self-assignment)
cTimes& cTimes::operator=(const cTimes& other) {
    if (this != &other) {
        delete[] arr;
        n   = other.n;
        arr = (n > 0) ? new CTime[n] : nullptr;
        for (int i = 0; i < n; ++i) arr[i] = other.arr[i];
    }
    return *this;
}
