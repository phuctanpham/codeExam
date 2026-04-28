/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Tinh tong thoi luong cua ca day (tich luy theo CTime duration)
CTime cTimes::sum() const {
    CTime total(0, 0, 0);
    for (int i = 0; i < n; ++i)
        total = total + arr[i]; // Tan dung OVERLOADING operator+(CTime)
    return total;
}
