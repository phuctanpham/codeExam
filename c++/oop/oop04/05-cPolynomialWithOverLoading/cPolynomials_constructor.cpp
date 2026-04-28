/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// Constructor mac dinh
cPolynomials::cPolynomials(int size) {
    n = size;
    arr = (n > 0) ? new cPolynomial[n] : nullptr;
}

// Copy Constructor (Deep Copy)
cPolynomials::cPolynomials(const cPolynomials& other) {
    n = other.n;
    arr = (n > 0) ? new cPolynomial[n] : nullptr;
    for (int i = 0; i < n; ++i) {
        arr[i] = other.arr[i]; // Toan tu = cua cPolynomial da duoc overload (Deep copy)
    }
}