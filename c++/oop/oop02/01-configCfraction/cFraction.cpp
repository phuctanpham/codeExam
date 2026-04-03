/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFraction.h"

#include <numeric>
#include <sstream>
#include <string>

using namespace std;

namespace {
// Doc va kiem tra phan so tu chuoi nhap theo dang a/b.
bool readFraction(const char* prompt, int& numerator, int& denominator) {
    string line;

    while (true) {
        cout << prompt;
        if (!getline(cin >> ws, line)) {
            return false;
        }

        stringstream stream(line);
        char slash = '\0';
        char extra = '\0';

        // Kiem tra dung dinh dang phan so a/b va khong co ky tu thua.
        if (!(stream >> numerator >> ws >> slash >> ws >> denominator) || slash != '/' || (stream >> extra)) {
            cout << "Sai định dạng, hãy nhập a/b.\n";
            continue;
        }

        // Mau so phai khac 0 de phan so hop le.
        if (denominator == 0) {
            cout << "Mẫu số phải khác 0, vui lòng nhập lại.\n";
            continue;
        }

        return true;
    }
}
}

// Khoi tao phan so mac dinh 0/1.
cFraction::cFraction() : numerator(0), denominator(1) {}

// Khoi tao phan so tu tu so va mau so.
cFraction::cFraction(int numerator, int denominator) {
    setValue(numerator, denominator);
}

// Rut gon phan so va dam bao mau so luon duong.
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

// Gan gia tri moi cho phan so, co xu ly mau so 0.
void cFraction::setValue(int newNumerator, int newDenominator) {
    numerator = newNumerator;
    denominator = (newDenominator == 0) ? 1 : newDenominator;
    normalize();
}

// Nhap phan so tu ban phim.
void cFraction::input() {
    int n = 0;
    int d = 1;
    readFraction("Nhập phân số (a/b): ", n, d);
    setValue(n, d);
}

// In phan so ra man hinh.
void cFraction::output() const {
    if (denominator == 1) {
        cout << numerator;
    } else {
        cout << numerator << "/" << denominator;
    }
}

// Cong hai phan so.
cFraction cFraction::add(const cFraction& other) const {
    return cFraction(
        numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator
    );
}

// Tru hai phan so.
cFraction cFraction::subtract(const cFraction& other) const {
    return cFraction(
        numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator
    );
}

// Nhan hai phan so.
cFraction cFraction::multiply(const cFraction& other) const {
    return cFraction(numerator * other.numerator, denominator * other.denominator);
}

// Chia hai phan so.
cFraction cFraction::divide(const cFraction& other) const {
    return cFraction(numerator * other.denominator, denominator * other.numerator);
}

// Lay tu so.
int cFraction::getNumerator() const {
    return numerator;
}

// Lay mau so.
int cFraction::getDenominator() const {
    return denominator;
}
