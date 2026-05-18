/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBook.h"

// --- Destructors ---
Sach::~Sach() {}
SachGiaoKhoa::~SachGiaoKhoa() {}
SachThamKhao::~SachThamKhao() {}

// --- Getters / Setters ---
double Sach::getDonGia()           const { return donGia; }
void   Sach::setDonGia(double gia)       { donGia = gia; }
string Sach::getNhaXuatBan()       const { return nhaXuatBan; }

// --- Base Class Output ---
void Sach::displayInfo(ostream& out) const {
    out << "Ma sach: "   << maSach
        << " | Ngay nhap: " << ngayNhap
        << " | NXB: "       << nhaXuatBan
        << " | So luong: "  << soLuong
        << " | Don gia: "   << fixed << setprecision(0) << donGia;
}

ostream& operator<<(ostream& out, const Sach& s) {
    s.displayInfo(out);
    return out;
}

// --- Textbook ---
double SachGiaoKhoa::tinhThanhTien() const {
    // FIX: inputInfo normalises tinhTrang to lowercase, so only one branch needed per value
    if (tinhTrang == "moi")
        return soLuong * donGia;
    else // "cu" or anything else treated as old
        return soLuong * donGia * 0.5;
}

void SachGiaoKhoa::displayInfo(ostream& out) const {
    out << "[SGK] ";
    Sach::displayInfo(out);
    out << " | Tinh trang: " << tinhTrang
        << " | Thanh tien: " << fixed << setprecision(0) << tinhThanhTien() << "\n";
}

// --- Reference Book ---
double SachThamKhao::tinhThanhTien() const {
    return (soLuong * donGia) + thue;
}

void SachThamKhao::displayInfo(ostream& out) const {
    out << "[STK] ";
    Sach::displayInfo(out);
    out << " | Thue: " << thue
        << " | Thanh tien: " << fixed << setprecision(0) << tinhThanhTien() << "\n";
}