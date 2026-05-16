/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// [Inheritance] Abstract Base class for general Books
class Sach {
protected:
    string maSach;
    string ngayNhap;
    double donGia;
    int soLuong;
    string nhaXuatBan;

public:
    // [Constructor / Destructor] functionability
    Sach();
    virtual ~Sach(); // Virtual destructor for safe polymorphic cleanup

    // [Getter / Setter] functionability
    double getDonGia() const;
    void setDonGia(double gia);
    string getNhaXuatBan() const;

    // [Override] Pure virtual functions
    virtual double tinhThanhTien() const = 0;
    virtual void inputInfo(istream& in) = 0;
    virtual void displayInfo(ostream& out) const = 0;

    // [Overloading] Operators for input/output streams
    friend istream& operator>>(istream& in, Sach& s);
    friend ostream& operator<<(ostream& out, const Sach& s);
};

// [Inheritance] Derived class for Textbooks (Sách giáo khoa)
class SachGiaoKhoa : public Sach {
private:
    string tinhTrang; // "moi" (new) or "cu" (old)

public:
    SachGiaoKhoa();
    ~SachGiaoKhoa() override;

    // [Override] Implementation of base functions
    double tinhThanhTien() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};

// [Inheritance] Derived class for Reference Books (Sách tham khảo)
class SachThamKhao : public Sach {
private:
    double thue;

public:
    SachThamKhao();
    ~SachThamKhao() override;

    // [Override] Implementation of base functions
    double tinhThanhTien() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};