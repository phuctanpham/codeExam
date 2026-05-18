/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBook.h"
#include <vector>

int main() {
    const int SO_LUONG_NHAP = 3;

    vector<SachGiaoKhoa> dsSGK;
    vector<SachThamKhao> dsSTK;
    // FIX: reserve before push_back to prevent reallocation (consistent safe pattern)
    dsSGK.reserve(SO_LUONG_NHAP);
    dsSTK.reserve(SO_LUONG_NHAP);

    double tongTienSGK    = 0.0;
    double tongTienSTK    = 0.0;
    double tongDonGiaSTK  = 0.0;

    // 1. Input
    cout << "=== NHAP DANH SACH SACH GIAO KHOA ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Quyen SGK thu " << i + 1 << " ---\n";
        SachGiaoKhoa s;
        cin >> s;
        tongTienSGK += s.tinhThanhTien();
        dsSGK.push_back(s);
    }

    cout << "\n=== NHAP DANH SACH SACH THAM KHAO ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Quyen STK thu " << i + 1 << " ---\n";
        SachThamKhao s;
        cin >> s;
        tongTienSTK   += s.tinhThanhTien();
        tongDonGiaSTK += s.getDonGia();
        dsSTK.push_back(s);
    }

    // 2. Output
    cout << "\n===========================================\n";
    cout << "=== DANH SACH SACH GIAO KHOA ===\n";
    for (const auto& sgk : dsSGK) cout << sgk;

    cout << "\n=== DANH SACH SACH THAM KHAO ===\n";
    for (const auto& stk : dsSTK) cout << stk;

    // 3. Totals
    // FIX: use setprecision(2) for the average so decimal part is visible
    double tbcDonGiaSTK = (SO_LUONG_NHAP > 0) ? (tongDonGiaSTK / SO_LUONG_NHAP) : 0.0;
    cout << "\n===========================================\n";
    cout << "TONG THANH TIEN SACH GIAO KHOA: " << fixed << setprecision(0) << tongTienSGK   << "\n";
    cout << "TONG THANH TIEN SACH THAM KHAO: " << tongTienSTK   << "\n";
    cout << "TRUNG BINH CONG DON GIA STK   : " << setprecision(2) << tbcDonGiaSTK << "\n";
    cout << "===========================================\n";

    // 4. Search by publisher K
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
    if (!found)
        cout << "Khong tim thay sach cua nha xuat ban nay.\n";

    return 0;
}