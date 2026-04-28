/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

cComplex cComplexes::max() const {
    if (n == 0) return cComplex(0, 0);
    cComplex maxValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxValue) { // Ap dung OVERLOADING > (dua vao modulus)
            maxValue = arr[i];
        }
    }
    return maxValue;
}