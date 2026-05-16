/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cOto_ChuyenXe.h"
#include <vector>

int main() {
    const int SO_LUONG_NHAP = 2; // Requirement: input 2 trips for each type

    vector<ChuyenXeNoiThanh> dsNoiThanh(SO_LUONG_NHAP);
    vector<ChuyenXeNgoaiThanh> dsNgoaiThanh(SO_LUONG_NHAP);
    
    double tongDoanhThuNoiThanh = 0;
    double tongDoanhThuNgoaiThanh = 0;

    // 1. Nhap thong tin [cite: 20, 24, 27]
    cout << "=== NHAP THONG TIN CHUYEN XE NOI THANH ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Chuyen noi thanh thu " << i + 1 << " ---\n";
        cin >> dsNoiThanh[i];
    }

    cout << "\n=== NHAP THONG TIN CHUYEN XE NGOAI THANH ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Chuyen ngoai thanh thu " << i + 1 << " ---\n";
        cin >> dsNgoaiThanh[i];
    }

    // 2. Xuat thong tin 
    cout << "\n===========================================\n";
    cout << "=== DANH SACH CHUYEN XE NOI THANH ===\n";
    for (const auto& cx : dsNoiThanh) {
        cout << cx;
        tongDoanhThuNoiThanh += cx.getDoanhThu();
    }

    cout << "\n=== DANH SACH CHUYEN XE NGOAI THANH ===\n";
    for (const auto& cx : dsNgoaiThanh) {
        cout << cx;
        tongDoanhThuNgoaiThanh += cx.getDoanhThu();
    }

    // 3. Tinh tong doanh thu 
    double tongDoanhThu = tongDoanhThuNoiThanh + tongDoanhThuNgoaiThanh;

    cout << "\n===========================================\n";
    cout << "TONG DOANH THU NOI THANH   : " << fixed << setprecision(0) << tongDoanhThuNoiThanh << "\n";
    cout << "TONG DOANH THU NGOAI THANH : " << tongDoanhThuNgoaiThanh << "\n";
    cout << "TONG DOANH THU TAT CA      : " << tongDoanhThu << "\n";
    cout << "===========================================\n";

    return 0;
}