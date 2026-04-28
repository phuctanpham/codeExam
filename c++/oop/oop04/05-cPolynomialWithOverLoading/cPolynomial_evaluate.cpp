/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// Tinh gia tri P(x) bang thuat toan Horner (Toi uu hon dung pow())
double cPolynomial::evaluate(double x) const {
    double res = heSo[bac];
    for (int i = bac - 1; i >= 0; --i) {
        res = res * x + heSo[i];
    }
    return res;
}