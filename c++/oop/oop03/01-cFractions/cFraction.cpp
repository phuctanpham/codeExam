/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFraction.h"

#include <iostream>
#include <numeric>
#include <sstream>

using namespace std;

namespace {
// Doc mot dong va kiem tra dinh dang phan so a/b.
bool readFractionLine(const string& prompt, int& numerator, int& denominator) {
    string line;

    while (true) {
        cout << prompt;
        if (!getline(cin >> ws, line)) {
            return false;
        }

        stringstream stream(line);
        char slash = '\0';
        char extra = '\0';

        if (!(stream >> numerator >> ws >> slash >> ws >> denominator) || slash != '/' || (stream >> extra)) {
            cout << "Sai dinh dang, hay nhap a/b.\n";
            continue;
        }

        if (denominator == 0) {
            cout << "Mau so phai khac 0, vui long nhap lai.\n";
            continue;
        }

        return true;
    }
}
}

// Phan dinh nghia doi tuong
cFraction::cFraction() : numerator(0), denominator(1) {}

cFraction::cFraction(int numerator, int denominator) {
    setValue(numerator, denominator);
}

void cFraction::normalize() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    int gcdValue = gcd(numerator, denominator);
    if (gcdValue != 0) {
        numerator /= gcdValue;
        denominator /= gcdValue;
    }
}

void cFraction::setValue(int newNumerator, int newDenominator) {
    numerator = newNumerator;
    denominator = (newDenominator == 0) ? 1 : newDenominator;
    normalize();
}

// Phan nhap du lieu
bool cFraction::input(const string& prompt) {
    int n = 0;
    int d = 1;

    if (!readFractionLine(prompt, n, d)) {
        return false;
    }

    setValue(n, d);
    return true;
}

// Phan xuat du lieu
void cFraction::output() const {
    if (denominator == 1) {
        cout << numerator;
        return;
    }

    cout << numerator << '/' << denominator;
}

double cFraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

int cFraction::getNumerator() const {
    return numerator;
}

int cFraction::getDenominator() const {
    return denominator;
}