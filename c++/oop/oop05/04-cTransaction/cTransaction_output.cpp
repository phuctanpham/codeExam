/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cGiaoDich_Transaction.h"

// --- Destructors ---
GiaoDich::~GiaoDich() {}
GiaoDichVang::~GiaoDichVang() {}
GiaoDichTienTe::~GiaoDichTienTe() {}

// --- Getters / Setters ---
double GiaoDich::getDonGia() const { return donGia; }
void GiaoDich::setDonGia(double dGia) { donGia = dGia; }
int GiaoDich::getSoLuong() const { return soLuong; }

string GiaoDichTienTe::getLoaiTienTe() const { return loaiTienTe; }

// --- Base Class Output Logic ---
void GiaoDich::displayInfo(ostream& out) const {
    out << "Ma GD: " << maGiaoDich << " | Ngay: " << ngayGiaoDich 
        << " | So luong: " << soLuong << " | Don gia: " << fixed << setprecision(0) << donGia;
}

// [Overloading] Stream insertion operator uses polymorphism
ostream& operator<<(ostream& out, const GiaoDich& gd) {
    gd.displayInfo(out);
    return out;
}

// --- Gold Transaction Logic ---
double GiaoDichVang::tinhThanhTien() const {
    return soLuong * donGia; // [cite: 45]
}

void GiaoDichVang::displayInfo(ostream& out) const {
    out << "[GD VANG] ";
    GiaoDich::displayInfo(out);
    out << " | Loai vang: " << loaiVang 
        << " | Thanh tien: " << tinhThanhTien() << "\n";
}

// --- Currency Transaction Logic ---
double GiaoDichTienTe::tinhThanhTien() const {
    if (loaiTienTe == "USD" || loaiTienTe == "Euro") {
        return soLuong * donGia * tiGia; // [cite: 48]
    } else { // Assuming VN if not USD or Euro
        return soLuong * donGia; // [cite: 49]
    }
}

void GiaoDichTienTe::displayInfo(ostream& out) const {
    out << "[GD TIEN TE] ";
    GiaoDich::displayInfo(out);
    out << " | Ti gia: " << tiGia << " | Loai tien: " << loaiTienTe 
        << " | Thanh tien: " << tinhThanhTien() << "\n";
}