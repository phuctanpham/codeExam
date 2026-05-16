/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudents_student.h"

// --- Destructors ---
SinhVien::~SinhVien() {}
SinhVienCaoDang::~SinhVienCaoDang() {}
SinhVienDaiHoc::~SinhVienDaiHoc() {}

// --- Getters / Setters ---
float SinhVien::getDiemTrungBinh() const { return diemTrungBinh; }
void SinhVien::setDiemTrungBinh(float dtb) { diemTrungBinh = dtb; }
string SinhVien::getHoTen() const { return hoTen; }

// --- Base Class Output Logic ---
void SinhVien::displayInfo(ostream& out) const {
    out << "MSSV: " << mssv << " | Ho Ten: " << hoTen 
        << " | Tin chi: " << tongTinChi << " | DTB: " << diemTrungBinh;
}

// [Overloading] Operator << outputs polymorphic objects safely
ostream& operator<<(ostream& out, const SinhVien& sv) {
    sv.displayInfo(out);
    return out;
}

// --- College Student Logic ---
bool SinhVienCaoDang::checkTotNghiep() const {
    // Condition: Credits >= 110, GPA >= 5, Grad Exam >= 5
    return (tongTinChi >= 110 && diemTrungBinh >= 5.0f && diemThiTotNghiep >= 5.0f);
}

void SinhVienCaoDang::displayInfo(ostream& out) const {
    out << "[Cao Dang] ";
    SinhVien::displayInfo(out);
    out << " | Diem thi TN: " << diemThiTotNghiep << "\n";
}

// --- University Student Logic ---
bool SinhVienDaiHoc::checkTotNghiep() const {
    // Condition: Credits >= 145, GPA >= 5, Thesis >= 5
    return (tongTinChi >= 145 && diemTrungBinh >= 5.0f && diemLuanVan >= 5.0f);
}

void SinhVienDaiHoc::displayInfo(ostream& out) const {
    out << "[Dai Hoc]  ";
    SinhVien::displayInfo(out);
    out << " | Luan van: " << tenLuanVan << " | Diem LV: " << diemLuanVan << "\n";
}