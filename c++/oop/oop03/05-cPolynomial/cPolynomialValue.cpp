/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomial.h"

using namespace std;

double cPolynomial::evaluate(double x) const {
    // Horner's method for efficient polynomial evaluation
    double result = 0.0;
    for (const double coef : coefficients) {
        result = result * x + coef;
    }
    return result;
}