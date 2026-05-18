/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cEmployee.h"
#include <vector>
#include <memory>

int main() {
    int nSX = 0, nVP = 0;
    // [Polymorphism] Single owning container of base-class pointers.
    // unique_ptr avoids dangling pointers caused by vector reallocation
    // (the original design stored &vector.back() into a separate list,
    // which becomes invalid the moment the source vector grows).
    vector<unique_ptr<NhanVien>> dsTongHop;

    // 1. Nhap danh sach
    cout << "=== NHAP DANH SACH NHAN VIEN SAN XUAT ===\n";
    cout << "So luong: "; cin >> nSX; cin.ignore();
    if (nSX < 0) nSX = 0;
    for (int i = 0; i < nSX; i++) {
        cout << "--- Nhan vien SX thu " << i + 1 << " ---\n";
        auto nv = make_unique<NhanVienSanXuat>();
        cin >> *nv;          // Overloaded >> (polymorphic)
        nv->tinhLuong();     // Calculate immediately upon input
        dsTongHop.push_back(std::move(nv));
    }

    cout << "\n=== NHAP DANH SACH NHAN VIEN VAN PHONG ===\n";
    cout << "So luong: "; cin >> nVP; cin.ignore();
    if (nVP < 0) nVP = 0;
    for (int i = 0; i < nVP; i++) {
        cout << "--- Nhan vien VP thu " << i + 1 << " ---\n";
        auto nv = make_unique<NhanVienVanPhong>();
        cin >> *nv;          // Overloaded >> (polymorphic)
        nv->tinhLuong();     // Calculate immediately upon input
        dsTongHop.push_back(std::move(nv));
    }

    // 2 & 3. Xuat danh sach va Tinh tong luong
    double tongTienLuongCty = 0.0;

    cout << "\n===========================================\n";
    cout << "=== DANH SACH TOAN BO NHAN VIEN ===\n";
    for (const auto& nv : dsTongHop) {
        cout << *nv;         // Overloaded << (polymorphic)
        tongTienLuongCty += nv->getLuong();
    }

    // 4. Tong luong phai tra
    cout << "\n===========================================\n";
    cout << "TONG QUY LUONG CONG TY PHAI TRA: "
         << fixed << setprecision(0) << tongTienLuongCty << " VND\n";
    cout << "===========================================\n";

    return 0;
}
