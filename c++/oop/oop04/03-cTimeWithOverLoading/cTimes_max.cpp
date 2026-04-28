/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Tim thoi diem lon nhat trong day
CTime cTimes::max() const {
    if (n == 0) return CTime(0, 0, 0);
    CTime result = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > result) result = arr[i]; // Tan dung OVERLOADING >
    return result;
}
