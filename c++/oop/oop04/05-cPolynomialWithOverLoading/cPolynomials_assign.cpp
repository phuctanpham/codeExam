/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// OVERLOADING toan tu gán (Deep copy, chong tu gan)
cPolynomials& cPolynomials::operator=(const cPolynomials& other) {
    if (this != &other) {
        delete[] arr;
        n = other.n;
        arr = (n > 0) ? new cPolynomial[n] : nullptr;
        for (int i = 0; i < n; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}