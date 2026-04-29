/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

cPolynomial cPolynomial::operator-(const cPolynomial& other) const {
    int maxBac = (bac > other.bac) ? bac : other.bac;
    cPolynomial res(maxBac);

    for (int i = 0; i <= maxBac; ++i) {
        double h1 = (i <= bac)       ? heSo[i]       : 0.0;
        double h2 = (i <= other.bac) ? other.heSo[i] : 0.0;
        res.heSo[i] = h1 - h2;
    }

    // [SUA] Goi normalize() sau phep tru de dieu chinh bac thuc su
    // Vi du: (x^2+1) - (x^2+3) = -2 → bac phai la 0, khong phai 2
    res.normalize();
    return res;
}
