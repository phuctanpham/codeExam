/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// [SUA] Thay so sanh != truc tiep bang nguong epsilon khi so sanh he so kieu double.
//        Ly do: so thuc dau phay dong co sai so tich luy khi tinh toan,
//        vi du 0.1 + 0.2 != 0.3 ve mat bieu dien nhi phan du ve toan hoc bang nhau.
//        Dung epsilon = 1e-9 dam bao so sanh chinh xac hon.
static const double EPSILON = 1e-9;

bool cPolynomial::operator==(const cPolynomial& other) const {
    if (bac != other.bac) return false;
    for (int i = bac; i >= 0; --i) {
        if (fabs(heSo[i] - other.heSo[i]) >= EPSILON) return false;
    }
    return true;
}

bool cPolynomial::operator!=(const cPolynomial& other) const {
    return !(*this == other);
}

bool cPolynomial::operator>(const cPolynomial& other) const {
    if (bac != other.bac) return bac > other.bac;
    for (int i = bac; i >= 0; --i) {
        if (fabs(heSo[i] - other.heSo[i]) >= EPSILON)
            return heSo[i] > other.heSo[i];
    }
    return false;
}

bool cPolynomial::operator<(const cPolynomial& other) const {
    if (bac != other.bac) return bac < other.bac;
    for (int i = bac; i >= 0; --i) {
        if (fabs(heSo[i] - other.heSo[i]) >= EPSILON)
            return heSo[i] < other.heSo[i];
    }
    return false;
}
