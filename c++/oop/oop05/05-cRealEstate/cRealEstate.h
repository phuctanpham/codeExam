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

// [Inheritance] Abstract Base class for Real Estate Transactions
class GiaoDichBDS {
protected:
    string maGiaoDich;
    string ngayGiaoDich; // Format: dd/mm/yyyy
    double donGia;
    double dienTich;

public:
    // [Constructor / Destructor]
    GiaoDichBDS();
    virtual ~GiaoDichBDS(); 

    // [Getter / Setter] functionability
    double getDonGia() const;
    void setDonGia(double dGia);
    string getNgayGiaoDich() const;

    // [Override] Pure virtual functions
    virtual double tinhThanhTien() const = 0;
    virtual void inputInfo(istream& in) = 0;
    virtual void displayInfo(ostream& out) const = 0;

    // [Overloading] Operators for input/output streams
    friend istream& operator>>(istream& in, GiaoDichBDS& bds);
    friend ostream& operator<<(ostream& out, const GiaoDichBDS& bds);
};

// [Inheritance] Derived class for Land Transactions
class GiaoDichDat : public GiaoDichBDS {
private:
    string loaiDat; // "A", "B", "C"

public:
    GiaoDichDat();
    ~GiaoDichDat() override;

    double tinhThanhTien() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};

// [Inheritance] Derived class for Townhouse Transactions
class GiaoDichNhaPho : public GiaoDichBDS {
private:
    string loaiNha; // "cao cap", "thuong"
    string diaChi;

public:
    GiaoDichNhaPho();
    ~GiaoDichNhaPho() override;

    double tinhThanhTien() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};

// [Inheritance] Derived class for Apartment Transactions
class GiaoDichChungCu : public GiaoDichBDS {
private:
    string maCan;
    int viTriTang;

public:
    GiaoDichChungCu();
    ~GiaoDichChungCu() override;

    double tinhThanhTien() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};