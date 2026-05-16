/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cSach_Sach.h"
#include <vector>

int main() {
    const int SO_LUONG_NHAP = 3; // Requirement: 3 of each type

    vector<SachGiaoKhoa> dsSGK(SO_LUONG_NHAP);
    vector<SachThamKhao> dsSTK(SO_LUONG_NHAP);

    double tongTienSGK = 0;
    double tongTienSTK = 0;
    double tongDonGiaSTK = 0;

    // 1. Nhap danh sach
    cout << "=== NHAP DANH SACH SACH GIAO KHOA ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Quyen SGK thu " << i + 1 << " ---\n";
        cin >> dsSGK[i];
        tongTienSGK += dsSGK[i].tinhThanhTien();
    }

    cout << "\n=== NHAP DANH SACH SACH THAM KHAO ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Quyen STK thu " << i + 1 << " ---\n";
        cin >> dsSTK[i];
        tongTienSTK += dsSTK[i].tinhThanhTien();
        tongDonGiaSTK += dsSTK[i].getDonGia();
    }

    // 2. Xuat danh sach
    cout << "\n===========================================\n";
    cout << "=== DANH SACH SACH GIAO KHOA ===\n";
    for (const auto& sgk : dsSGK) cout << sgk;

    cout << "\n=== DANH SACH SACH THAM KHAO ===\n";
    for (const auto& stk : dsSTK) cout << stk;

    // 3. Tong thanh tien
    cout << "\n===========================================\n";
    cout << "TONG THANH TIEN SACH GIAO KHOA: " << fixed << setprecision(0) << tongTienSGK << "\n";
    cout << "TONG THANH TIEN SACH THAM KHAO: " << tongTienSTK << "\n";

    // 4. Trung binh cong don gia sach tham khao
    double tbcDonGiaSTK = (SO_LUONG_NHAP > 0) ? (tongDonGiaSTK / SO_LUONG_NHAP) : 0;
    cout << "TRUNG BINH CONG DON GIA STK   : " << tbcDonGiaSTK << "\n";
    cout << "===========================================\n";

    // 5. Xuat sach giao khoa cua nha xuat ban K
    string nxbTimKiem;
    cout << "\nNhap ten Nha xuat ban K can tim: ";
    getline(cin, nxbTimKiem);

    cout << "=== CAC SACH GIAO KHOA CUA NXB '" << nxbTimKiem << "' ===\n";
    bool found = false;
    for (const auto& sgk : dsSGK) {
        if (sgk.getNhaXuatBan() == nxbTimKiem) {
            cout << sgk;
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay sach cua nha xuat ban nay.\n";
    }

    return 0;
}