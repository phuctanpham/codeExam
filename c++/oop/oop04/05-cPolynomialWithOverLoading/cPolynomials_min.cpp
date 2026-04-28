/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

cPolynomial cPolynomials::min() const {
    if (n == 0) return cPolynomial(0);
    cPolynomial minPoly = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minPoly) { // Su dung toan tu < cua cPolynomial
            minPoly = arr[i];
        }
    }
    return minPoly;
}