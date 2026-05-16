/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBatDongSan_RealEstate.h"
#include <limits>

// --- Base Class: GiaoDichBDS ---
GiaoDichBDS::GiaoDichBDS() : maGiaoDich(""), ngayGiaoDich(""), donGia(0.0), dienTich(0.0) {}

void GiaoDichBDS::inputInfo(istream& in) {
    cout << "Nhap Ma giao dich: "; getline(in, maGiaoDich);
    cout << "Nhap Ngay giao dich (dd/mm/yyyy): "; getline(in, ngayGiaoDich);
    cout << "Nhap Don gia: "; in >> donGia;
    cout << "Nhap Dien tich: "; in >> dienTich;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}

// [Overloading] Stream extraction operator uses polymorphism
istream& operator>>(istream& in, GiaoDichBDS& bds) {
    bds.inputInfo(in);
    return in;
}

// --- Derived Class: GiaoDichDat ---
GiaoDichDat::GiaoDichDat() : GiaoDichBDS(), loaiDat("") {}

void GiaoDichDat::inputInfo(istream& in) {
    GiaoDichBDS::inputInfo(in);
    cout << "Nhap Loai dat (A/B/C): "; getline(in, loaiDat);
}

// --- Derived Class: GiaoDichNhaPho ---
GiaoDichNhaPho::GiaoDichNhaPho() : GiaoDichBDS(), loaiNha(""), diaChi("") {}

void GiaoDichNhaPho::inputInfo(istream& in) {
    GiaoDichBDS::inputInfo(in);
    cout << "Nhap Loai nha (cao cap/thuong): "; getline(in, loaiNha);
    cout << "Nhap Dia chi: "; getline(in, diaChi);
}

// --- Derived Class: GiaoDichChungCu ---
GiaoDichChungCu::GiaoDichChungCu() : GiaoDichBDS(), maCan(""), viTriTang(0) {}

void GiaoDichChungCu::inputInfo(istream& in) {
    GiaoDichBDS::inputInfo(in);
    cout << "Nhap Ma can: "; getline(in, maCan);
    cout << "Nhap Vi tri tang: "; in >> viTriTang;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}