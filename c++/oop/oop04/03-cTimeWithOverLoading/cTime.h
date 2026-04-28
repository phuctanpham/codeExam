/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CTIME_H
#define CTIME_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class CTime {
private:
    int gio, phut, giay;
    void chuanHoa(); // Xu ly tran giay, phut va quay vong 24h

public:
    // Constructor & Destructor
    CTime(int h = 0, int m = 0, int s = 0);
    ~CTime();

    // Overloading Toan tu Nhap/Xuat
    friend istream& operator>>(istream& is, CTime& t);
    friend ostream& operator<<(ostream& os, const CTime& t);

    // Overloading Toan tu So hoc (Cong/Tru voi so nguyen giay)
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    // Overloading Toan tu Tang/Giam (1 giay)
    CTime& operator++();    // Tien to: ++t
    CTime operator++(int);  // Hau to: t++
    CTime& operator--();    // Tien to: --t
    CTime operator--(int);  // Hau to: t--

    // Overloading Toan tu So sanh
    bool operator==(const CTime& other) const;
    bool operator!=(const CTime& other) const;
    bool operator>(const CTime& other) const;
    bool operator<(const CTime& other) const;

    // Overloading Toan tu Tru giua 2 thoi diem (Tra ve tong so giay chenh lech)
    int operator-(const CTime& other) const;
};

#endif