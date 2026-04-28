/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CTIMES_H
#define CTIMES_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// --- Lop bieu dien 1 thoi diem ---
class CTime {
private:
    int gio, phut, giay;
    void chuanHoa();

public:
    CTime(int h = 0, int m = 0, int s = 0);
    ~CTime();

    // Overloading Toan tu Nhap/Xuat
    friend istream& operator>>(istream& is, CTime& t);
    friend ostream& operator<<(ostream& os, const CTime& t);

    // Overloading Cong/Tru voi so nguyen giay
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    // [THEM MOI] Cong/Tru voi mot khoang thoi gian (CTime dong vai tro thoi luong)
    CTime operator+(const CTime& duration) const;
    CTime operator-(const CTime& duration) const;

    // Overloading Tang/Giam 1 giay
    CTime& operator++();
    CTime  operator++(int);
    CTime& operator--();
    CTime  operator--(int);

    // Overloading So sanh
    bool operator==(const CTime& other) const;
    bool operator!=(const CTime& other) const;
    bool operator>(const CTime& other) const;
    bool operator<(const CTime& other) const;

    // [SUA] Tra ve CTime (thay vi int giay) de bieu dien chenh lech dang hh:mm:ss
    CTime difference(const CTime& other) const;
};

// --- Lop bieu dien day cac thoi diem ---
// [THEM MOI] Lop cTimes tuong tu cFractions / cComplexes cua 2 bai truoc
class cTimes {
private:
    int n;
    CTime* arr;
public:
    cTimes(int size = 0);
    cTimes(const cTimes& other);   // Copy constructor - tranh shallow copy
    ~cTimes();

    cTimes& operator=(const cTimes& other); // Deep copy assignment

    friend istream& operator>>(istream& is, cTimes& ts);
    friend ostream& operator<<(ostream& os, const cTimes& ts);

    CTime sum()  const; // Tong thoi luong
    CTime max()  const; // Thoi diem lon nhat
    CTime min()  const; // Thoi diem nho nhat
    void sortAscending();
};

#endif
