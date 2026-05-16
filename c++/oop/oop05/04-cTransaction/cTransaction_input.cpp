/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cGiaoDich_Transaction.h"
#include <limits>

// --- Base Class: GiaoDich ---
GiaoDich::GiaoDich() : maGiaoDich(""), ngayGiaoDich(""), donGia(0.0), soLuong(0) {}

void GiaoDich::inputInfo(istream& in) {
    cout << "Nhap Ma giao dich: "; getline(in, maGiaoDich);
    cout << "Nhap Ngay giao dich (dd/mm/yyyy): "; getline(in, ngayGiaoDich);
    cout << "Nhap Don gia: "; in >> donGia;
    cout << "Nhap So luong: "; in >> soLuong;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}

// [Overloading] Stream extraction operator uses polymorphism
istream& operator>>(istream& in, GiaoDich& gd) {
    gd.inputInfo(in);
    return in;
}

// --- Derived Class: GiaoDichVang ---
GiaoDichVang::GiaoDichVang() : GiaoDich(), loaiVang("") {}

void GiaoDichVang::inputInfo(istream& in) {
    GiaoDich::inputInfo(in);
    cout << "Nhap Loai vang: "; getline(in, loaiVang);
}

// --- Derived Class: GiaoDichTienTe ---
GiaoDichTienTe::GiaoDichTienTe() : GiaoDich(), tiGia(0.0), loaiTienTe("") {}

void GiaoDichTienTe::inputInfo(istream& in) {
    GiaoDich::inputInfo(in);
    cout << "Nhap Ti gia: "; in >> tiGia;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap Loai tien te (VN/USD/Euro): "; getline(in, loaiTienTe);
}