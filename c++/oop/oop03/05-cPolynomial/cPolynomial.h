/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_POLYNOMIAL_H
#define C_POLYNOMIAL_H

#include <string>
#include <vector>

using namespace std;

class cPolynomial {
private:
    vector<double> coefficients; // Ordered from highest degree to constant term
    string polynomialName;

    static int instanceCount;
    static constexpr double EPS = 1e-9;

    static bool almostEqual(double a, double b);
    void normalize();

public:
    cPolynomial();
    cPolynomial(const vector<double>& coeffs, const string& name = "DA THUC");
    ~cPolynomial();

    static int getInstanceCount();

    bool setup(const vector<double>& coeffs, const string& name = "DA THUC");
    void input();
    void output() const;

    bool isZeroPolynomial() const;
    int degree() const;
    double evaluate(double x) const;
    double maxValueWith(const cPolynomial& other, double x) const;

    cPolynomial derivative() const;
    cPolynomial add(const cPolynomial& other) const;
    cPolynomial subtract(const cPolynomial& other) const;
    cPolynomial multiply(const cPolynomial& other) const;
    cPolynomial quotient(const cPolynomial& divisor) const;

    vector<double> getCoefficients() const;
};

#endif