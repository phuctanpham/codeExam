/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Constructor mac dinh va Copy Constructor cho lop cTimes
cTimes::cTimes(int size) {
    n   = size;
    arr = (n > 0) ? new CTime[n] : nullptr;
}

// Copy Constructor - thuc hien Deep Copy tranh loi shallow copy con tro
cTimes::cTimes(const cTimes& other) {
    n   = other.n;
    arr = (n > 0) ? new CTime[n] : nullptr;
    for (int i = 0; i < n; ++i) arr[i] = other.arr[i];
}
