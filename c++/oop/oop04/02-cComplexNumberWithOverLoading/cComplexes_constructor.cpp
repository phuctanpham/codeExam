/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

// Constructor mac dinh
cComplexes::cComplexes(int size) {
    n = size;
    arr = (n > 0) ? new cComplex[n] : nullptr;
}

// Copy Constructor (Deep Copy de an toan bo nho)
cComplexes::cComplexes(const cComplexes& other) {
    n = other.n;
    arr = (n > 0) ? new cComplex[n] : nullptr;
    for (int i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
}