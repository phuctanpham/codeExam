/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cNhanVien_Employee.h"
#include <vector>

int main() {
    int nSX, nVP;
    vector<NhanVienSanXuat> dsSanXuat;
    vector<NhanVienVanPhong> dsVanPhong;
    vector<NhanVien*> dsTongHop;

    // 1. Nhap danh sach
    cout << "=== NHAP DANH SACH NHAN VIEN SAN XUAT ===\n";
    cout << "So luong: "; cin >> nSX; cin.ignore();
    for (int i = 0; i < nSX; i++) {
        cout << "--- Nhan vien SX thu " << i + 1 << " ---\n";
        NhanVienSanXuat nv;
        cin >> nv; // Overloaded >>
        nv.tinhLuong(); // Calculate immediately upon input
        dsSanXuat.push_back(nv);
        dsTongHop.push_back(&dsSanXuat.back());
    }

    cout << "\n=== NHAP DANH SACH NHAN VIEN VAN PHONG ===\n";
    cout << "So luong: "; cin >> nVP; cin.ignore();
    for (int i = 0; i < nVP; i++) {
        cout << "--- Nhan vien VP thu " << i + 1 << " ---\n";
        NhanVienVanPhong nv;
        cin >> nv; // Overloaded >>
        nv.tinhLuong(); // Calculate immediately upon input
        dsVanPhong.push_back(nv);
        dsTongHop.push_back(&dsVanPhong.back());
    }

    // 2 & 3. Xuat danh sach va Tinh tong luong
    double tongTienLuongCty = 0;

    cout << "\n===========================================\n";
    cout << "=== DANH SACH TOAN BO NHAN VIEN ===\n";
    for (const auto* nv : dsTongHop) {
        cout << *nv; // Overloaded <<
        tongTienLuongCty += nv->getLuong();
    }

    // 4. Tong luong phai tra
    cout << "\n===========================================\n";
    cout << "TONG QUY LUONG CONG TY PHAI TRA: " << fixed << setprecision(0) << tongTienLuongCty << " VND\n";
    cout << "===========================================\n";

    return 0;
}