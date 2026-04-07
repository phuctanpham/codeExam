/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <vector>

#include "cPolynomial.h"

using namespace std;

cPolynomial cPolynomial::derivative() const {
    if (degree() == 0) {
        return cPolynomial({0.0}, polynomialName + "'");
    }

    vector<double> derivCoeffs;
    const int n = degree();
    derivCoeffs.reserve(static_cast<size_t>(n));

    for (int i = 0; i < n; ++i) {
        const int power = n - i;
        derivCoeffs.push_back(coefficients[static_cast<size_t>(i)] * static_cast<double>(power));
    }

    return cPolynomial(derivCoeffs, polynomialName + "'");
}