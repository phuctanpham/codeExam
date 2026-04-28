/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// OVERLOADING toan tu gán (Deep copy, chong tu gan)
cPolynomial& cPolynomial::operator=(const cPolynomial& other) {
    if (this != &other) {
        delete[] heSo;
        bac = other.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; ++i) {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}