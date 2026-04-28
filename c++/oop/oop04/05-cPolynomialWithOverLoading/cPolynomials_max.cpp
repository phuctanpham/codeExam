/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

cPolynomial cPolynomials::max() const {
    if (n == 0) return cPolynomial(0);
    cPolynomial maxPoly = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxPoly) { // Su dung toan tu > cua cPolynomial
            maxPoly = arr[i];
        }
    }
    return maxPoly;
}