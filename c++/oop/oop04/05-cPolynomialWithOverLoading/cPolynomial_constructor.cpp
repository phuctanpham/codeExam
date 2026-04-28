/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// Constructor mac dinh
cPolynomial::cPolynomial(int b) {
    bac = (b >= 0) ? b : 0;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        heSo[i] = 0.0;
    }
}

// Copy Constructor (Deep Copy)
cPolynomial::cPolynomial(const cPolynomial& other) {
    bac = other.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        heSo[i] = other.heSo[i];
    }
}