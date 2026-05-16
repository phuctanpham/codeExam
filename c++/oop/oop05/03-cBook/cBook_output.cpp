/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cSach_Sach.h"

// --- Destructors ---
Sach::~Sach() {}
SachGiaoKhoa::~SachGiaoKhoa() {}
SachThamKhao::~SachThamKhao() {}

// --- Getters / Setters ---
double Sach::getDonGia() const { return donGia; }
void Sach::setDonGia(double gia) { donGia = gia; }
string Sach::getNhaXuatBan() const { return nhaXuatBan; }

// --- Base Class Output Logic ---
void Sach::displayInfo(ostream& out) const {
    out << "Ma sach: " << maSach << " | Ngay nhap: " << ngayNhap 
        << " | NXB: " << nhaXuatBan << " | So luong: " << soLuong 
        << " | Don gia: " << fixed << setprecision(0) << donGia;
}

// [Overloading] Stream insertion operator
ostream& operator<<(ostream& out, const Sach& s) {
    s.displayInfo(out);
    return out;
}

// --- Textbook (Sach Giao Khoa) Logic ---
double SachGiaoKhoa::tinhThanhTien() const {
    if (tinhTrang == "moi" || tinhTrang == "Moi") {
        return soLuong * donGia;
    } else {
        return soLuong * donGia * 0.5; // 50% for old books
    }
}

void SachGiaoKhoa::displayInfo(ostream& out) const {
    out << "[SGK] ";
    Sach::displayInfo(out);
    out << " | Tinh trang: " << tinhTrang 
        << " | Thanh tien: " << tinhThanhTien() << "\n";
}

// --- Reference Book (Sach Tham Khao) Logic ---
double SachThamKhao::tinhThanhTien() const {
    return (soLuong * donGia) + thue;
}

void SachThamKhao::displayInfo(ostream& out) const {
    out << "[STK] ";
    Sach::displayInfo(out);
    out << " | Thue: " << thue 
        << " | Thanh tien: " << tinhThanhTien() << "\n";
}