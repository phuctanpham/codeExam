/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexNumber.h"

cComplex cComplexes::min() const {
    if (n == 0) return cComplex(0, 0);
    cComplex minValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minValue) { // Ap dung OVERLOADING < (dua vao modulus)
            minValue = arr[i];
        }
    }
    return minValue;
}