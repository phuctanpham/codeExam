/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

cFraction cFractions::max() {
    if (n == 0) return cFraction(0, 1);
    cFraction maxValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxValue) { // Tận dụng OVERLOADING >
            maxValue = arr[i];
        }
    }
    return maxValue;
}