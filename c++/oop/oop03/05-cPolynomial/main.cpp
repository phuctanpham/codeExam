/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iomanip>
#include <iostream>

#include "cPolynomial.h"

using namespace std;

int main() {
    cout << "===== CHUONG TRINH MINH HOA LOP cPolynomial =====\n\n";

    cPolynomial p1({0.0}, "P");
    cout << "Nhap da thuc P(x):\n";
    p1.input();

    cPolynomial p2({0.0}, "Q");
    cout << "\nNhap da thuc Q(x):\n";
    p2.input();

    cout << "\n===== cPolynomialOutput.cpp =====\n";
    cout << "P(x):\n";
    p1.output();
    cout << "Q(x):\n";
    p2.output();

    cout << "\n===== cPolynomialCheck.cpp =====\n";
    cout << "Bac P(x) = " << p1.degree() << "\n";
    cout << "P(x) la da thuc 0: " << (p1.isZeroPolynomial() ? "Co" : "Khong") << "\n";
    cout << "Bac Q(x) = " << p2.degree() << "\n";
    cout << "Q(x) la da thuc 0: " << (p2.isZeroPolynomial() ? "Co" : "Khong") << "\n";

    double x = 0.0;
    cout << "\n===== cPolynomialValue.cpp =====\n";
    cout << "Nhap gia tri x de tinh P(x), Q(x): ";
    cin >> x;
    cout << fixed << setprecision(3);
    const double pValue = p1.evaluate(x);
    const double qValue = p2.evaluate(x);
    const double maxValue = p1.maxValueWith(p2, x);

    cout << "P(" << x << ") = " << pValue << "\n";
    cout << "Q(" << x << ") = " << qValue << "\n";
    cout << "\n===== cPolynomialMaxValue.cpp =====\n";
    cout << "Gia tri lon nhat giua hai bieu thuc = " << maxValue << "\n";

    cout << "\n===== cPolynomialDerivative.cpp =====\n";
    cPolynomial dp = p1.derivative();
    cPolynomial dq = p2.derivative();
    cout << "Dao ham P'(x):\n";
    dp.output();
    cout << "Dao ham Q'(x):\n";
    dq.output();

    cout << "\n===== cPolynomialAdd.cpp =====\n";
    cPolynomial sum = p1.add(p2);
    cPolynomial f(sum.getCoefficients(), "F");
    cout << "F(x) = P(x) + Q(x)\n";
    f.output();

    cout << "\n===== cPolynomialSubtract.cpp =====\n";
    cPolynomial diff = p1.subtract(p2);
    cPolynomial fDiff(diff.getCoefficients(), "F");
    cout << "F(x) = P(x) - Q(x)\n";
    fDiff.output();

    cout << "\n===== cPolynomialMultiply.cpp =====\n";
    cPolynomial product = p1.multiply(p2);
    cPolynomial fProduct(product.getCoefficients(), "F");
    cout << "F(x) = P(x) * Q(x)\n";
    fProduct.output();

    cout << "\n===== cPolynomialQuotient.cpp =====\n";

    if (p2.isZeroPolynomial()) {
        cout << "Khong the tinh thuong vi Q(x) la da thuc 0.\n";
    } else {
        cout << "F(x) = P(x) / Q(x) (thuong)\n";
        cPolynomial quotient = p1.quotient(p2);
        cPolynomial remainder = p1.subtract(p2.multiply(quotient));
        cPolynomial fQuotient(quotient.getCoefficients(), "F");
        cPolynomial rQuotient(remainder.getCoefficients(), "R");
        fQuotient.output();
        cout << "Du R(x):\n";
        rQuotient.output();
    }

    if (p1.isZeroPolynomial()) {
        cout << "Khong the tinh thuong vi P(x) la da thuc 0.\n";
    } else {
        cout << "F(x) = Q(x) / P(x) (thuong)\n";
        cPolynomial quotientReverse = p2.quotient(p1);
        cPolynomial remainderReverse = p2.subtract(p1.multiply(quotientReverse));
        cPolynomial fQuotientReverse(quotientReverse.getCoefficients(), "F");
        cPolynomial rQuotientReverse(remainderReverse.getCoefficients(), "R");
        fQuotientReverse.output();
        cout << "Du R(x):\n";
        rQuotientReverse.output();
    }

    return 0;
}