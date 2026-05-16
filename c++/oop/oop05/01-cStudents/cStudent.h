/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// [Inheritance] Base class for common attributes
class SinhVien {
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongTinChi;
    float diemTrungBinh;

public:
    // [Constructor / Destructor]
    SinhVien();
    virtual ~SinhVien(); // Virtual destructor ensures derived destructors are called

    // [Getter / Setter] functionability
    float getDiemTrungBinh() const;
    void setDiemTrungBinh(float dtb);
    string getHoTen() const;

    // [Override] Pure virtual functions make this an abstract class
    virtual bool checkTotNghiep() const = 0; 
    virtual void inputInfo(istream& in) = 0;
    virtual void displayInfo(ostream& out) const = 0;

    // [Overloading] Operators for input/output streams
    friend istream& operator>>(istream& in, SinhVien& sv);
    friend ostream& operator<<(ostream& out, const SinhVien& sv);
};

// [Inheritance] Derived class for College Students
class SinhVienCaoDang : public SinhVien {
private:
    float diemThiTotNghiep;

public:
    SinhVienCaoDang();
    ~SinhVienCaoDang() override;

    // [Override] Implementing base class virtual functions
    bool checkTotNghiep() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};

// [Inheritance] Derived class for University Students
class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    float diemLuanVan;

public:
    SinhVienDaiHoc();
    ~SinhVienDaiHoc() override;

    // [Override] Implementing base class virtual functions
    bool checkTotNghiep() const override;
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};