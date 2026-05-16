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

// [Inheritance] Abstract Base class for generic Transactions
class GiaoDich {
protected:
    string maGiaoDich;
    string ngayGiaoDich;
    double donGia;
    int soLuong;

public:
    // [Constructor / Destructor]
    GiaoDich();
    virtual ~GiaoDich(); // Virtual destructor for safe polymorphic cleanup

    // [Getter / Setter] functionability
    double getDonGia() const;
    void setDonGia(double dGia);
    int getSoLuong() const;

    // [Override] Pure virtual functions
    virtual double tinhThanhTien() const = 0;
    virtual void inputInfo(istream& in) = 0;
    virtual void displayInfo(ostream& out) const = 0;

    // [Overloading] Operators for input/output streams
    friend istream& operator>>(istream& in, GiaoDich& gd);
    friend ostream& operator<<(ostream& out, const GiaoDich& gd);
};

// [Inheritance] Derived class for Gold Transactions
class GiaoDichVang : public GiaoDich {
private:
    string loaiVang;

public:
    GiaoDichVang();
    ~GiaoDichVang() override;

    // [Override] Implementation for Gold specific logic
    double tinhThanhTien() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};

// [Inheritance] Derived class for Currency Transactions
class GiaoDichTienTe : public GiaoDich {
private:
    double tiGia;
    string loaiTienTe; // "VN", "USD", "Euro"

public:
    GiaoDichTienTe();
    ~GiaoDichTienTe() override;

    // Getter specifically for Euro filtering requirement
    string getLoaiTienTe() const;

    // [Override] Implementation for Currency specific logic
    double tinhThanhTien() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};