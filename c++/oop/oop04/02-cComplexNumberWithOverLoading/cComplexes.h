/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CCOMPLEXES_H
#define CCOMPLEXES_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// --- Lop bieu dien 1 so phuc ---
class cComplex {
private:
    float thuc, ao;
public:
    cComplex(float t = 0, float a = 0);
    ~cComplex();

    float modulus() const;

    friend istream& operator>>(istream& is, cComplex& c);
    friend ostream& operator<<(ostream& os, const cComplex& c);

    cComplex operator+(const cComplex& other) const;
    cComplex operator-(const cComplex& other) const;
    cComplex operator*(const cComplex& other) const;
    cComplex operator/(const cComplex& other) const;

    bool operator==(const cComplex& other) const;
    bool operator!=(const cComplex& other) const;
    bool operator>(const cComplex& other) const;
    bool operator<(const cComplex& other) const;
};

// --- Lop bieu dien day so phuc ---
class cComplexes {
private:
    int n;
    cComplex* arr;
public:
    cComplexes(int size = 0);
    cComplexes(const cComplexes& other);
    ~cComplexes();

    cComplexes& operator=(const cComplexes& other);

    friend istream& operator>>(istream& is, cComplexes& cs);
    friend ostream& operator<<(ostream& os, const cComplexes& cs);

    cComplex sum() const;
    cComplex max() const;
    cComplex min() const;
    void sortAscending();
};

#endif