/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cSach_Sach.h"
#include <limits>

// --- Base Class: Sach ---
Sach::Sach() : maSach(""), ngayNhap(""), donGia(0.0), soLuong(0), nhaXuatBan("") {}

void Sach::inputInfo(istream& in) {
    cout << "Nhap Ma sach: "; getline(in, maSach);
    cout << "Nhap Ngay nhap (dd/mm/yyyy): "; getline(in, ngayNhap);
    cout << "Nhap Don gia: "; in >> donGia;
    cout << "Nhap So luong: "; in >> soLuong;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap Nha xuat ban: "; getline(in, nhaXuatBan);
}

// [Overloading] Stream extraction operator
istream& operator>>(istream& in, Sach& s) {
    s.inputInfo(in);
    return in;
}

// --- Derived Class: SachGiaoKhoa ---
SachGiaoKhoa::SachGiaoKhoa() : Sach(), tinhTrang("") {}

void SachGiaoKhoa::inputInfo(istream& in) {
    Sach::inputInfo(in);
    cout << "Nhap Tinh trang (moi/cu): "; getline(in, tinhTrang);
}

// --- Derived Class: SachThamKhao ---
SachThamKhao::SachThamKhao() : Sach(), thue(0.0) {}

void SachThamKhao::inputInfo(istream& in) {
    Sach::inputInfo(in);
    cout << "Nhap Thue: "; in >> thue;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}