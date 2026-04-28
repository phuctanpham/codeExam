/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CDATES_H
#define CDATES_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// ==========================================
// LOP CDATE: Xu ly mot moc thoi gian (Ngay/Thang/Nam)
// ==========================================
class cDate {
private:
    int ngay, thang, nam;

    // Cac ham tien ich xu ly lich
    bool isLeapYear() const;
    int daysInMonth() const;
    void chuanHoa(); 

public:
    // Constructor (mac dinh la 01/01/0001) & Destructor
    cDate(int d = 1, int m = 1, int y = 1);
    ~cDate();

    // Overloading Nhap / Xuat
    friend istream& operator>>(istream& is, cDate& d);
    friend ostream& operator<<(ostream& os, const cDate& d);

    // Overloading toan tu so hoc (+, - voi so nguyen ngay)
    cDate operator+(int days) const;
    cDate operator-(int days) const;

    // Overloading toan tu tru 2 CDate (Tra ve so nguyen ngay chenh lech)
    int operator-(const cDate& other) const; 

    // Overloading toan tu tang/giam
    cDate& operator++();    // Tien to: ++d
    cDate operator++(int);  // Hau to: d++
    cDate& operator--();    // Tien to: --d
    cDate operator--(int);  // Hau to: d--

    // Overloading toan tu so sanh
    bool operator==(const cDate& other) const;
    bool operator!=(const cDate& other) const;
    bool operator>(const cDate& other) const;
    bool operator<(const cDate& other) const;

    // Phuong thuc bo tro
    string getWeekday() const;
};

// ==========================================
// LOP CDATES: Xu ly mang / day cac moc thoi gian
// ==========================================
class cDates {
private:
    int n;
    cDate* arr;
public:
    // Rule of Three (Chong ro ri bo nho va tu gan)
    cDates(int size = 0);
    cDates(const cDates& other); 
    ~cDates();
    cDates& operator=(const cDates& other); 

    // Overloading Nhap / Xuat mang
    friend istream& operator>>(istream& is, cDates& ds);
    friend ostream& operator<<(ostream& os, const cDates& ds);

    // Xu ly mang
    cDate max() const;
    cDate min() const;
    void sortAscending();
};

#endif