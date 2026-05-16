/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cOto_ChuyenXe.h"

// --- Destructors ---
ChuyenXe::~ChuyenXe() {}
ChuyenXeNoiThanh::~ChuyenXeNoiThanh() {}
ChuyenXeNgoaiThanh::~ChuyenXeNgoaiThanh() {}

// --- Getters / Setters ---
double ChuyenXe::getDoanhThu() const { return doanhThu; }
void ChuyenXe::setDoanhThu(double dThu) { doanhThu = dThu; }

// --- Base Class: ChuyenXe ---
void ChuyenXe::displayInfo(ostream& out) const {
    out << "Ma chuyen: " << maSoChuyen << " | Tai xe: " << hoTenTaiXe 
        << " | So xe: " << soXe << " | Doanh thu: " << fixed << setprecision(0) << doanhThu;
}

// [Overloading] Stream insertion operator uses polymorphism
ostream& operator<<(ostream& out, const ChuyenXe& cx) {
    cx.displayInfo(out);
    return out;
}

// --- Derived Class: ChuyenXeNoiThanh ---
void ChuyenXeNoiThanh::displayInfo(ostream& out) const {
    out << "[Noi Thanh]  ";
    ChuyenXe::displayInfo(out);
    out << " | Tuyen: " << soTuyen << " | So km: " << soKm << "\n";
}

// --- Derived Class: ChuyenXeNgoaiThanh ---
void ChuyenXeNgoaiThanh::displayInfo(ostream& out) const {
    out << "[Ngoai Thanh] ";
    ChuyenXe::displayInfo(out);
    out << " | Noi den: " << noiDen << " | So ngay: " << soNgay << "\n";
}