/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

cFraction cFractions::sum() {
    cFraction total(0, 1);
    for (int i = 0; i < n; ++i) {
        total = total + arr[i]; // Tận dụng OVERLOADING +
    }
    return total;
}