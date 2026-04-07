/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <vector>

#include "cPolynomial.h"

using namespace std;

cPolynomial cPolynomial::quotient(const cPolynomial& divisor) const {
    if (divisor.isZeroPolynomial() || almostEqual(divisor.coefficients[0], 0.0)) {
        return cPolynomial({0.0}, "Khong the chia cho da thuc 0");
    }

    const int degA = degree();
    const int degB = divisor.degree();

    if (degA < degB) {
        return cPolynomial({0.0}, "Thuong hai da thuc");
    }

    vector<double> rem = coefficients;
    vector<double> quot(static_cast<size_t>(degA - degB) + 1, 0.0);

    for (int i = 0; i <= degA - degB; ++i) {
        if (almostEqual(rem[static_cast<size_t>(i)], 0.0)) {
            continue;
        }

        const double factor = rem[static_cast<size_t>(i)] / divisor.coefficients[0];
        quot[static_cast<size_t>(i)] = factor;

        for (int j = 0; j <= degB; ++j) {
            rem[static_cast<size_t>(i + j)] -= factor * divisor.coefficients[static_cast<size_t>(j)];
        }
    }

    return cPolynomial(quot, "Thuong hai da thuc");
}
