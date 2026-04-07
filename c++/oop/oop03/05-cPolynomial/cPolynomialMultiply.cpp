/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <vector>

#include "cPolynomial.h"

using namespace std;

cPolynomial cPolynomial::multiply(const cPolynomial& other) const {
    const int degA = degree();
    const int degB = other.degree();
    const int degR = degA + degB;

    vector<double> result(static_cast<size_t>(degR) + 1, 0.0);

    for (size_t i = 0; i < coefficients.size(); ++i) {
        const int powerA = degA - static_cast<int>(i);
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            const int powerB = degB - static_cast<int>(j);
            const int powerR = powerA + powerB;
            const int indexR = degR - powerR;

            result[static_cast<size_t>(indexR)] += coefficients[i] * other.coefficients[j];
        }
    }

    return cPolynomial(result, "Tich hai da thuc");
}