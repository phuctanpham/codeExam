/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <cmath>

#include "cPolynomial.h"

using namespace std;

int cPolynomial::instanceCount = 0;

cPolynomial::cPolynomial() : polynomialName("DA THUC") {
    coefficients = {0.0};
    ++instanceCount;
}

cPolynomial::cPolynomial(const vector<double>& coeffs, const string& name)
    : polynomialName(name) {
    setup(coeffs, name);
    ++instanceCount;
}

cPolynomial::~cPolynomial() {
    if (instanceCount > 0) {
        --instanceCount;
    }
}

int cPolynomial::getInstanceCount() {
    return instanceCount;
}

bool cPolynomial::almostEqual(double a, double b) {
    return fabs(a - b) <= EPS;
}

void cPolynomial::normalize() {
    size_t firstNonZero = 0;
    while (firstNonZero < coefficients.size() && almostEqual(coefficients[firstNonZero], 0.0)) {
        ++firstNonZero;
    }

    if (firstNonZero == coefficients.size()) {
        coefficients = {0.0};
        return;
    }

    if (firstNonZero > 0) {
        coefficients.erase(coefficients.begin(), coefficients.begin() + static_cast<long>(firstNonZero));
    }
}

bool cPolynomial::setup(const vector<double>& coeffs, const string& name) {
    if (coeffs.empty()) {
        return false;
    }

    coefficients = coeffs;
    polynomialName = name;
    normalize();

    return true;
}

vector<double> cPolynomial::getCoefficients() const {
    return coefficients;
}