/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomial.h"

using namespace std;

bool cPolynomial::isZeroPolynomial() const {
    return coefficients.size() == 1 && almostEqual(coefficients[0], 0.0);
}

int cPolynomial::degree() const {
    if (isZeroPolynomial()) {
        return 0;
    }
    return static_cast<int>(coefficients.size()) - 1;
}