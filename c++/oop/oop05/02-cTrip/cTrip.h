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

// [Inheritance] Base class for general Bus Trip properties
class ChuyenXe {
protected:
    string maSoChuyen;
    string hoTenTaiXe;
    string soXe;
    double doanhThu;

public:
    // [Constructor / Destructor]
    ChuyenXe();
    virtual ~ChuyenXe(); 

    // [Getter / Setter] functionability for Revenue calculation
    double getDoanhThu() const;
    void setDoanhThu(double dThu);

    // [Override] Pure virtual functions to enforce abstraction
    virtual void inputInfo(istream& in) = 0;
    virtual void displayInfo(ostream& out) const = 0;

    // [Overloading] Operators for unified input/output processing
    friend istream& operator>>(istream& in, ChuyenXe& cx);
    friend ostream& operator<<(ostream& out, const ChuyenXe& cx);
};

// [Inheritance] Derived class for Inner-city Trips
class ChuyenXeNoiThanh : public ChuyenXe {
private:
    string soTuyen;
    float soKm;

public:
    ChuyenXeNoiThanh();
    ~ChuyenXeNoiThanh() override;

    // [Override] Specializing input/output for inner-city
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};

// [Inheritance] Derived class for Inter-city Trips
class ChuyenXeNgoaiThanh : public ChuyenXe {
private:
    string noiDen;
    int soNgay;

public:
    ChuyenXeNgoaiThanh();
    ~ChuyenXeNgoaiThanh() override;

    // [Override] Specializing input/output for inter-city
    void inputInfo(istream& in) override;
    void displayInfo(ostream& out) const override;
};