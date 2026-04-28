/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Sap xep day thoi diem tang dan (dung selection sort + OVERLOADING >)
void cTimes::sortAscending() {
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (arr[i] > arr[j]) {
                CTime temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
