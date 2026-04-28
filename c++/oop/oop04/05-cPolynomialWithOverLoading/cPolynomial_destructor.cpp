/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

cPolynomial::~cPolynomial() {
    if (heSo != nullptr) {
        delete[] heSo;
        heSo = nullptr;
    }
}