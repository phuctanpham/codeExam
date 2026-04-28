/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Giai phong bo nho dong cap phat khi doi tuong bi huy
cTimes::~cTimes() {
    delete[] arr;
    arr = nullptr;
}
