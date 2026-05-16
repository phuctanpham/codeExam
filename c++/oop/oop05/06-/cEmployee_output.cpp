/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cNhanVien_Employee.h"

// --- Destructors ---
NhanVien::~NhanVien() {}
NhanVienSanXuat::~NhanVienSanXuat() {}
NhanVienVanPhong::~NhanVienVanPhong() {}

// --- Getters / Setters ---
double NhanVien::getLuong() const { return luong; }
void NhanVien::setLuong(double l) { luong = l; }
string NhanVien::getHoTen() const { return hoTen; }

// --- Base Class Output Logic ---
void NhanVien::displayInfo(ostream& out) const {
    out << "Ho ten: " << hoTen << " | Ngay sinh: " << ngaySinh 
        << " | Luong: " << fixed << setprecision(0) << luong;
}

// [Overloading] Stream insertion operator uses polymorphism
ostream& operator<<(ostream& out, const NhanVien& nv) {
    nv.displayInfo(out);
    return out;
}

// --- Production Employee Logic ---
void NhanVienSanXuat::tinhLuong() {
    luong = luongCanBan + (soSanPham * 5000.0);
}

void NhanVienSanXuat::displayInfo(ostream& out) const {
    out << "[NV SAN XUAT]  ";
    NhanVien::displayInfo(out);
    out << " | LCB: " << luongCanBan << " | So SP: " << soSanPham << "\n";
}

// --- Office Employee Logic ---
void NhanVienVanPhong::tinhLuong() {
    luong = soNgayLamViec * 100000.0;
}

void NhanVienVanPhong::displayInfo(ostream& out) const {
    out << "[NV VAN PHONG] ";
    NhanVien::displayInfo(out);
    out << " | Ngay cong: " << soNgayLamViec << "\n";
}