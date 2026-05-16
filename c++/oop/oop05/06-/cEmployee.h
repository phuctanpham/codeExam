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

// [Inheritance] Abstract Base class representing a generic Employee
class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luong;

public:
    // [Constructor / Destructor] functionability
    NhanVien();
    virtual ~NhanVien(); // Virtual destructor ensures proper cleanup of derived objects

    // [Getter / Setter] functionability
    double getLuong() const;
    void setLuong(double l);
    string getHoTen() const;

    // [Override] Pure virtual functions to enforce implementation in derived classes
    virtual void tinhLuong() = 0;
    virtual void inputInfo(istream& in) = 0;
    virtual void displayInfo(ostream& out) const = 0;

    // [Overloading] Operators for clean stream I/O operations
    friend istream& operator>>(istream& in, NhanVien& nv);
    friend ostream& operator<<(ostream& out, const NhanVien& nv);
};

// [Inheritance] Derived class for Production Employees
class NhanVienSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    NhanVienSanXuat();
    ~NhanVienSanXuat() override;

    // [Override] Specific implementations for production staff
    void tinhLuong() override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};

// [Inheritance] Derived class for Office Employees
class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    NhanVienVanPhong();
    ~NhanVienVanPhong() override;

    // [Override] Specific implementations for office staff
    void tinhLuong() override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};