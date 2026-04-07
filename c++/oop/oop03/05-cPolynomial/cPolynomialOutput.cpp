/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <cmath>
#include <iomanip>
#include <iostream>

#include "cPolynomial.h"

using namespace std;

void cPolynomial::output() const {
    cout << fixed << setprecision(3);
    cout << "Da thuc: " << polynomialName << "\n";
    cout << "Bac da thuc: " << degree() << "\n";

    cout << polynomialName << "(x) = ";
    if (isZeroPolynomial()) {
        cout << 0.0;
    } else {
        bool isFirstTerm = true;
        const int n = degree();

        for (size_t i = 0; i < coefficients.size(); ++i) {
            const double coef = coefficients[i];
            const int power = n - static_cast<int>(i);

            if (almostEqual(coef, 0.0)) {
                continue;
            }

            const bool isNegative = coef < 0.0;
            const double absCoef = fabs(coef);

            if (isFirstTerm) {
                if (isNegative) {
                    cout << "-";
                }
            } else {
                cout << (isNegative ? " - " : " + ");
            }

            const bool showCoef = (power == 0) || !almostEqual(absCoef, 1.0);
            if (showCoef) {
                cout << absCoef;
            }

            if (power > 0) {
                cout << "x";
                if (power > 1) {
                    cout << "^" << power;
                }
            }

            isFirstTerm = false;
        }
    }
    cout << "\n";
}