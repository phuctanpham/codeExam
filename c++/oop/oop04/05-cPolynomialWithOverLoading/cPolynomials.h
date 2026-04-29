/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CPOLYNOMIALS_H
#define CPOLYNOMIALS_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// ==========================================
// LOP CPOLYNOMIAL: Xu ly 1 Da thuc
// ==========================================
class cPolynomial {
private:
    int bac;
    double* heSo; // Mang dong luu he so tu bac 0 den bac n

    // [THEM MOI] Ham chuan hoa: giam bac neu he so bac cao nhat bang 0
    // Vi du: [3, 0, 0] bac=2 → [3] bac=0 (hang so 3, khong phai 0x^2 + 0x + 3)
    // Can thiet sau phep cong/tru de bac noi bo khop voi bac toan hoc thuc su
    void normalize();

public:
    // Rule of Three
    cPolynomial(int b = 0);
    cPolynomial(const cPolynomial& other);
    ~cPolynomial();
    cPolynomial& operator=(const cPolynomial& other);

    // Overloading Nhap / Xuat
    friend istream& operator>>(istream& is, cPolynomial& p);
    friend ostream& operator<<(ostream& os, const cPolynomial& p);

    // Overloading Toan tu Toan hoc
    cPolynomial operator+(const cPolynomial& other) const;
    cPolynomial operator-(const cPolynomial& other) const;
    cPolynomial operator*(const cPolynomial& other) const;

    // Toan tu So sanh
    bool operator==(const cPolynomial& other) const;
    bool operator!=(const cPolynomial& other) const;
    bool operator>(const cPolynomial& other) const;
    bool operator<(const cPolynomial& other) const;

    // Tinh gia tri P(x)
    double evaluate(double x) const;
};

// ==========================================
// LOP CPOLYNOMIALS: Xu ly mang cac Da thuc
// ==========================================
class cPolynomials {
private:
    int n;
    cPolynomial* arr;

public:
    // Rule of Three
    cPolynomials(int size = 0);
    cPolynomials(const cPolynomials& other);
    ~cPolynomials();
    cPolynomials& operator=(const cPolynomials& other);

    // Overloading Nhap / Xuat
    friend istream& operator>>(istream& is, cPolynomials& ps);
    friend ostream& operator<<(ostream& os, const cPolynomials& ps);

    // Xu ly mang
    cPolynomial max() const;
    cPolynomial min() const;
    void sortAscending();
};

#endif
