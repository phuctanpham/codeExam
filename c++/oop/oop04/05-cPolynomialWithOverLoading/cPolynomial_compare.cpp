/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// So sanh uu tien Bậc -> Hệ số từ bậc cao xuống thấp
bool cPolynomial::operator==(const cPolynomial& other) const {
    if (bac != other.bac) return false;
    for (int i = bac; i >= 0; --i) {
        if (heSo[i] != other.heSo[i]) return false;
    }
    return true;
}

bool cPolynomial::operator!=(const cPolynomial& other) const {
    return !(*this == other);
}

bool cPolynomial::operator>(const cPolynomial& other) const {
    if (bac != other.bac) return bac > other.bac;
    for (int i = bac; i >= 0; --i) {
        if (heSo[i] != other.heSo[i]) return heSo[i] > other.heSo[i];
    }
    return false; // Bang nhau
}

bool cPolynomial::operator<(const cPolynomial& other) const {
    if (bac != other.bac) return bac < other.bac;
    for (int i = bac; i >= 0; --i) {
        if (heSo[i] != other.heSo[i]) return heSo[i] < other.heSo[i];
    }
    return false;
}