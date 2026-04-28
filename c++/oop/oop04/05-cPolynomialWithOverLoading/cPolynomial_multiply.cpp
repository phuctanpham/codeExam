/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

cPolynomial cPolynomial::operator*(const cPolynomial& other) const {
    int newBac = bac + other.bac;
    cPolynomial res(newBac);
    
    for (int i = 0; i <= bac; ++i) {
        for (int j = 0; j <= other.bac; ++j) {
            res.heSo[i + j] += (heSo[i] * other.heSo[j]);
        }
    }
    return res;
}