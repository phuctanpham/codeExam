/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CACCOUNT_H
#define CACCOUNT_H

#include "cDates.h" // Import lop CDate de xu ly ngay gui va ngay rut

class cAccount {
private:
    double soTienGui;
    double laiSuatNam;
    cDate ngayGui;
    cDate ngayRut;

public:
    cAccount(double tien = 0, double lai = 0);
    ~cAccount();

    // Overloading toan tu Nhap / Xuat
    friend istream& operator>>(istream& is, cAccount& acc);
    friend ostream& operator<<(ostream& os, const cAccount& acc);

    // Cac ham nghiep vu ngan hang
    int getSoNgayGui() const;
    double tinhTienLai() const;
};

#endif