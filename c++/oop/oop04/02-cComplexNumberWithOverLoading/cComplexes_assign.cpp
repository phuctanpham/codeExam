/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexNumber.h"

// OVERLOADING toan tu = (Deep Copy)
cComplexes& cComplexes::operator=(const cComplexes& other) {
    if (this != &other) { // Chong tu gan
        delete[] arr;
        n = other.n;
        arr = (n > 0) ? new cComplex[n] : nullptr;
        for (int i = 0; i < n; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}