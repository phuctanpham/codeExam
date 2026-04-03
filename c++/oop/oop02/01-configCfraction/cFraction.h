/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_FRACTION_H
#define C_FRACTION_H

#include <iostream>

class cFraction {
private:
    int numerator;
    int denominator;

    void normalize();

public:
    cFraction();
    cFraction(int numerator, int denominator);

    void setValue(int numerator, int denominator);

    void input();
    void output() const;

    cFraction add(const cFraction& other) const;
    cFraction subtract(const cFraction& other) const;
    cFraction multiply(const cFraction& other) const;
    cFraction divide(const cFraction& other) const;

    int getNumerator() const;
    int getDenominator() const;
};

#endif
