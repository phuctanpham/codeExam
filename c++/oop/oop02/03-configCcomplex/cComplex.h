/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_COMPLEX_H
#define C_COMPLEX_H

#include <iostream>

class cComplex {
private:
    double real;
    double imaginary;

public:
    cComplex();
    cComplex(double real, double imaginary);
    cComplex(const cComplex& other);

    void setValue(double newReal, double newImaginary);

    void input();
    void output() const;

    cComplex add(const cComplex& other) const;
    cComplex subtract(const cComplex& other) const;
    cComplex multiply(const cComplex& other) const;
    cComplex divide(const cComplex& other) const;

    bool isZero() const;
};

#endif
