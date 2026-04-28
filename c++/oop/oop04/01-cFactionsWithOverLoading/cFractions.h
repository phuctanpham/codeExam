/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CFRACTIONS_H
#define CFRACTIONS_H

#include <iostream>
using namespace std;

// --- Lớp biểu diễn 1 phân số ---
class cFraction {
private:
    int tu, mau;
    void simplify(); 
public:
    // OVERLOADING Constructor: Thiết lập phân số mặc định hoặc chuyển 1 số nguyên thành phân số (mẫu = 1)
    cFraction(int t = 0, int m = 1);
    ~cFraction();

    // OVERLOADING Toán tử Nhập/Xuất
    friend istream& operator>>(istream& is, cFraction& f);
    friend ostream& operator<<(ostream& os, const cFraction& f);

    // OVERLOADING Toán tử Số học
    cFraction operator+(const cFraction& other);
    cFraction operator-(const cFraction& other);
    cFraction operator*(const cFraction& other);
    cFraction operator/(const cFraction& other);

    // OVERLOADING Toán tử So sánh
    bool operator==(const cFraction& other);
    bool operator>(const cFraction& other);
    bool operator<(const cFraction& other);
};

// --- Lớp biểu diễn 1 dãy phân số ---
class cFractions {
private:
    int n;
    cFraction* arr;
public:
    cFractions(int size = 0);
    ~cFractions();

    // OVERLOADING Toán tử Nhập/Xuất cho cả dãy
    friend istream& operator>>(istream& is, cFractions& fs);
    friend ostream& operator<<(ostream& os, const cFractions& fs);

    cFraction sum();
    cFraction max();
    cFraction min();
    void sortAscending();
};

#endif