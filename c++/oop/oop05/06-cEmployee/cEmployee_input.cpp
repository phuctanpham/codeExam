/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cEmployee.h"
#include <limits>

// --- Base Class: NhanVien ---
NhanVien::NhanVien() : hoTen(""), ngaySinh(""), luong(0.0) {}

void NhanVien::inputInfo(istream& in) {
    cout << "Nhap Ho ten: "; getline(in, hoTen);
    cout << "Nhap Ngay sinh (dd/mm/yyyy): "; getline(in, ngaySinh);
}

// [Overloading] Stream extraction operator uses polymorphism
istream& operator>>(istream& in, NhanVien& nv) {
    nv.inputInfo(in);
    return in;
}

// --- Derived Class: NhanVienSanXuat ---
NhanVienSanXuat::NhanVienSanXuat() : NhanVien(), luongCanBan(0.0), soSanPham(0) {}

void NhanVienSanXuat::inputInfo(istream& in) {
    NhanVien::inputInfo(in);
    cout << "Nhap Luong can ban: "; in >> luongCanBan;
    cout << "Nhap So san pham: "; in >> soSanPham;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- Derived Class: NhanVienVanPhong ---
NhanVienVanPhong::NhanVienVanPhong() : NhanVien(), soNgayLamViec(0) {}

void NhanVienVanPhong::inputInfo(istream& in) {
    NhanVien::inputInfo(in);
    cout << "Nhap So ngay lam viec: "; in >> soNgayLamViec;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}
