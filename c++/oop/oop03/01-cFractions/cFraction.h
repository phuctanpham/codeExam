/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_FRACTION_H
#define C_FRACTION_H

#include <iostream>
#include <string>

using namespace std;

class cFraction {
private:
    int numerator;
    int denominator;

    void normalize();

public:
    cFraction();
    cFraction(int numerator, int denominator);

    void setValue(int numerator, int denominator);

    bool input(const string& prompt = "Nhap phan so (a/b): ");
    void output() const;
    double toDouble() const;

    int getNumerator() const;
    int getDenominator() const;
};

#endif