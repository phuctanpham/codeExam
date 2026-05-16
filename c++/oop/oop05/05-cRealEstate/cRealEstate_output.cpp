/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBatDongSan_RealEstate.h"

// --- Destructors ---
GiaoDichBDS::~GiaoDichBDS() {}
GiaoDichDat::~GiaoDichDat() {}
GiaoDichNhaPho::~GiaoDichNhaPho() {}
GiaoDichChungCu::~GiaoDichChungCu() {}

// --- Getters / Setters ---
double GiaoDichBDS::getDonGia() const { return donGia; }
void GiaoDichBDS::setDonGia(double dGia) { donGia = dGia; }
string GiaoDichBDS::getNgayGiaoDich() const { return ngayGiaoDich; }

// --- Base Class Output Logic ---
void GiaoDichBDS::displayInfo(ostream& out) const {
    out << "Ma GD: " << maGiaoDich << " | Ngay: " << ngayGiaoDich 
        << " | Dien tich: " << dienTich << " | Don gia: " << fixed << setprecision(0) << donGia;
}

// [Overloading] Stream insertion operator uses polymorphism
ostream& operator<<(ostream& out, const GiaoDichBDS& bds) {
    bds.displayInfo(out);
    return out;
}

// --- Land Transaction Logic ---
double GiaoDichDat::tinhThanhTien() const {
    if (loaiDat == "A" || loaiDat == "a") {
        return dienTich * donGia * 1.5; // [cite: 62]
    }
    return dienTich * donGia; // Type B or C [cite: 61]
}

void GiaoDichDat::displayInfo(ostream& out) const {
    out << "[GD DAT]     ";
    GiaoDichBDS::displayInfo(out);
    out << " | Loai dat: " << loaiDat << " | Thanh tien: " << tinhThanhTien() << "\n";
}

// --- Townhouse Transaction Logic ---
double GiaoDichNhaPho::tinhThanhTien() const {
    if (loaiNha == "cao cap") {
        return dienTich * donGia; // [cite: 64]
    }
    return dienTich * donGia * 0.9; // Type thuong gets 90% [cite: 65]
}

void GiaoDichNhaPho::displayInfo(ostream& out) const {
    out << "[GD NHA PHO] ";
    GiaoDichBDS::displayInfo(out);
    out << " | Loai nha: " << loaiNha << " | Dia chi: " << diaChi << " | Thanh tien: " << tinhThanhTien() << "\n";
}

// --- Apartment Transaction Logic ---
double GiaoDichChungCu::tinhThanhTien() const {
    if (viTriTang == 1) {
        return dienTich * donGia * 2.0; // [cite: 67]
    } else if (viTriTang >= 15) {
        return dienTich * donGia * 1.2; // [cite: 68]
    }
    return dienTich * donGia; // Other floors [cite: 69]
}

void GiaoDichChungCu::displayInfo(ostream& out) const {
    out << "[GD CHUNG CU]";
    GiaoDichBDS::displayInfo(out);
    out << " | Ma can: " << maCan << " | Tang: " << viTriTang << " | Thanh tien: " << tinhThanhTien() << "\n";
}