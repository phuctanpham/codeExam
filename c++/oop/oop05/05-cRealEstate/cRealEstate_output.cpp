/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cRealEstate.h"

// --- Destructors ---
GiaoDichBDS::~GiaoDichBDS() {}
GiaoDichDat::~GiaoDichDat() {}
GiaoDichNhaPho::~GiaoDichNhaPho() {}
GiaoDichChungCu::~GiaoDichChungCu() {}

// --- Getters / Setters ---
double GiaoDichBDS::getDonGia()              const { return donGia; }
void   GiaoDichBDS::setDonGia(double dGia)         { donGia = dGia; }
string GiaoDichBDS::getNgayGiaoDich()        const { return ngayGiaoDich; }

// --- Base Class Output ---
void GiaoDichBDS::displayInfo(ostream& out) const {
    out << "Ma GD: "      << maGiaoDich
        << " | Ngay: "    << ngayGiaoDich
        << " | Dien tich: " << dienTich
        << " | Don gia: " << fixed << setprecision(0) << donGia;
}

ostream& operator<<(ostream& out, const GiaoDichBDS& bds) {
    bds.displayInfo(out);
    return out;
}

// --- Land Transaction ---
// FIX: inputInfo normalises loaiDat to uppercase, so only one branch needed per value
double GiaoDichDat::tinhThanhTien() const {
    if (loaiDat == "A")
        return dienTich * donGia * 1.5;
    return dienTich * donGia; // B or C
}

void GiaoDichDat::displayInfo(ostream& out) const {
    out << "[GD DAT]      ";
    GiaoDichBDS::displayInfo(out);
    out << " | Loai dat: " << loaiDat
        << " | Thanh tien: " << fixed << setprecision(0) << tinhThanhTien() << "\n";
}

// --- Townhouse Transaction ---
// FIX: inputInfo normalises loaiNha to lowercase, so only one branch needed
double GiaoDichNhaPho::tinhThanhTien() const {
    if (loaiNha == "cao cap")
        return dienTich * donGia;
    return dienTich * donGia * 0.9; // "thuong"
}

void GiaoDichNhaPho::displayInfo(ostream& out) const {
    out << "[GD NHA PHO]  ";
    GiaoDichBDS::displayInfo(out);
    out << " | Loai nha: " << loaiNha
        << " | Dia chi: "  << diaChi
        << " | Thanh tien: " << fixed << setprecision(0) << tinhThanhTien() << "\n";
}

// --- Apartment Transaction ---
double GiaoDichChungCu::tinhThanhTien() const {
    if (viTriTang == 1)
        return dienTich * donGia * 2.0;
    if (viTriTang >= 15)
        return dienTich * donGia * 1.2;
    return dienTich * donGia;
}

void GiaoDichChungCu::displayInfo(ostream& out) const {
    out << "[GD CHUNG CU] ";
    GiaoDichBDS::displayInfo(out);
    out << " | Ma can: "  << maCan
        << " | Tang: "    << viTriTang
        << " | Thanh tien: " << fixed << setprecision(0) << tinhThanhTien() << "\n";
}
