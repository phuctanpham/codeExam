/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <vector>

#include "cPolynomial.h"

using namespace std;

cPolynomial cPolynomial::subtract(const cPolynomial& other) const {
    const int degA = degree();
    const int degB = other.degree();
    const int maxDeg = (degA > degB) ? degA : degB;

    vector<double> result(static_cast<size_t>(maxDeg) + 1, 0.0);

    for (int i = 0; i <= maxDeg; ++i) {
        const int power = maxDeg - i;

        double coefA = 0.0;
        if (power <= degA) {
            coefA = coefficients[static_cast<size_t>(degA - power)];
        }

        double coefB = 0.0;
        if (power <= degB) {
            coefB = other.coefficients[static_cast<size_t>(degB - power)];
        }

        result[static_cast<size_t>(i)] = coefA - coefB;
    }

    return cPolynomial(result, "Hieu hai da thuc");
}