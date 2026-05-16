/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudents_student.h"
#include <limits>

// --- Base Class: SinhVien ---
SinhVien::SinhVien() : mssv(""), hoTen(""), diaChi(""), tongTinChi(0), diemTrungBinh(0.0f) {}

void SinhVien::inputInfo(istream& in) {
    cout << "Nhap MSSV: "; getline(in, mssv);
    cout << "Nhap Ho ten: "; getline(in, hoTen);
    cout << "Nhap Dia chi: "; getline(in, diaChi);
    cout << "Nhap Tong tin chi: "; in >> tongTinChi;
    cout << "Nhap Diem trung binh: "; in >> diemTrungBinh;
    in.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
}

// [Overloading & Override] The >> operator is overloaded, but it relies on the overridden virtual inputInfo()
istream& operator>>(istream& in, SinhVien& sv) {
    sv.inputInfo(in);
    return in;
}

// --- Derived Class: SinhVienCaoDang ---
SinhVienCaoDang::SinhVienCaoDang() : SinhVien(), diemThiTotNghiep(0.0f) {}

void SinhVienCaoDang::inputInfo(istream& in) {
    SinhVien::inputInfo(in); // Reuse base class logic
    cout << "Nhap Diem thi tot nghiep: "; in >> diemThiTotNghiep;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- Derived Class: SinhVienDaiHoc ---
SinhVienDaiHoc::SinhVienDaiHoc() : SinhVien(), tenLuanVan(""), diemLuanVan(0.0f) {}

void SinhVienDaiHoc::inputInfo(istream& in) {
    SinhVien::inputInfo(in);
    cout << "Nhap Ten luan van: "; getline(in, tenLuanVan);
    cout << "Nhap Diem luan van: "; in >> diemLuanVan;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}