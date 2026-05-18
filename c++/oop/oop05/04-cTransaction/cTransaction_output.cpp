/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"

// --- Destructors ---
GiaoDich::~GiaoDich() {}
GiaoDichVang::~GiaoDichVang() {}
GiaoDichTienTe::~GiaoDichTienTe() {}

// --- Getters / Setters ---
double GiaoDich::getDonGia()           const { return donGia; }
void   GiaoDich::setDonGia(double dGia)      { donGia = dGia; }
int    GiaoDich::getSoLuong()          const { return soLuong; }

string GiaoDichTienTe::getLoaiTienTe() const { return loaiTienTe; }

// --- Base Class Output ---
void GiaoDich::displayInfo(ostream& out) const {
    out << "Ma GD: "     << maGiaoDich
        << " | Ngay: "   << ngayGiaoDich
        << " | So luong: " << soLuong
        << " | Don gia: " << fixed << setprecision(0) << donGia;
}

ostream& operator<<(ostream& out, const GiaoDich& gd) {
    gd.displayInfo(out);
    return out;
}

// --- Gold Transaction ---
double GiaoDichVang::tinhThanhTien() const {
    return soLuong * donGia;
}

void GiaoDichVang::displayInfo(ostream& out) const {
    out << "[GD VANG]    ";
    GiaoDich::displayInfo(out);
    out << " | Loai vang: " << loaiVang
        << " | Thanh tien: " << fixed << setprecision(0) << tinhThanhTien() << "\n";
}

// --- Currency Transaction ---
double GiaoDichTienTe::tinhThanhTien() const {
    if (loaiTienTe == "USD" || loaiTienTe == "Euro")
        return soLuong * donGia * tiGia;
    else // VN dong
        return soLuong * donGia;
}

void GiaoDichTienTe::displayInfo(ostream& out) const {
    out << "[GD TIEN TE] ";
    GiaoDich::displayInfo(out);
    out << " | Ti gia: "     << tiGia
        << " | Loai tien: "  << loaiTienTe
        << " | Thanh tien: " << fixed << setprecision(0) << tinhThanhTien() << "\n";
}
