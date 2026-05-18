/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTrip.h"
#include <limits>

// --- Base Class: ChuyenXe ---
ChuyenXe::ChuyenXe() : maSoChuyen(""), hoTenTaiXe(""), soXe(""), doanhThu(0.0) {}

void ChuyenXe::inputInfo(istream& in) {
    cout << "Nhap Ma so chuyen: ";  getline(in, maSoChuyen);
    cout << "Nhap Ho ten tai xe: "; getline(in, hoTenTaiXe);
    cout << "Nhap So xe: ";         getline(in, soXe);
    cout << "Nhap Doanh thu: ";     in >> doanhThu;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}

istream& operator>>(istream& in, ChuyenXe& cx) {
    cx.inputInfo(in);
    return in;
}

// --- Derived Class: ChuyenXeNoiThanh ---
ChuyenXeNoiThanh::ChuyenXeNoiThanh() : ChuyenXe(), soTuyen(""), soKm(0.0f) {}

void ChuyenXeNoiThanh::inputInfo(istream& in) {
    ChuyenXe::inputInfo(in);
    cout << "Nhap So tuyen: ";       getline(in, soTuyen);
    cout << "Nhap So km di duoc: "; in >> soKm;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- Derived Class: ChuyenXeNgoaiThanh ---
ChuyenXeNgoaiThanh::ChuyenXeNgoaiThanh() : ChuyenXe(), noiDen(""), soNgay(0) {}

void ChuyenXeNgoaiThanh::inputInfo(istream& in) {
    ChuyenXe::inputInfo(in);
    cout << "Nhap Noi den: ";          getline(in, noiDen);
    cout << "Nhap So ngay di duoc: "; in >> soNgay;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
}