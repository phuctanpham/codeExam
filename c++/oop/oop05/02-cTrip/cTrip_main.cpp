/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTrip.h"
#include <vector>

int main() {
    const int SO_LUONG_NHAP = 2;

    // FIX: use reserve() + push_back instead of vector(N) + operator[].
    // vector(N) default-constructs N objects, then operator>> overwrites them
    // via the base-class reference — which is fine here since ChuyenXe is
    // not polymorphically stored, but reserve+push_back is the cleaner,
    // consistent pattern (mirrors cStudent pattern and avoids double-init).
    vector<ChuyenXeNoiThanh>  dsNoiThanh;
    vector<ChuyenXeNgoaiThanh> dsNgoaiThanh;
    dsNoiThanh.reserve(SO_LUONG_NHAP);
    dsNgoaiThanh.reserve(SO_LUONG_NHAP);

    double tongDoanhThuNoiThanh   = 0.0;
    double tongDoanhThuNgoaiThanh = 0.0;

    // 1. Input
    cout << "=== NHAP THONG TIN CHUYEN XE NOI THANH ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Chuyen noi thanh thu " << i + 1 << " ---\n";
        ChuyenXeNoiThanh cx;
        cin >> cx;
        dsNoiThanh.push_back(cx);
    }

    cout << "\n=== NHAP THONG TIN CHUYEN XE NGOAI THANH ===\n";
    for (int i = 0; i < SO_LUONG_NHAP; i++) {
        cout << "--- Chuyen ngoai thanh thu " << i + 1 << " ---\n";
        ChuyenXeNgoaiThanh cx;
        cin >> cx;
        dsNgoaiThanh.push_back(cx);
    }

    // 2. Output + accumulate revenue
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

    // 3. Revenue summary
    double tongDoanhThu = tongDoanhThuNoiThanh + tongDoanhThuNgoaiThanh;

    cout << "\n===========================================\n";
    cout << "TONG DOANH THU NOI THANH   : " << fixed << setprecision(0) << tongDoanhThuNoiThanh   << "\n";
    cout << "TONG DOANH THU NGOAI THANH : " << tongDoanhThuNgoaiThanh << "\n";
    cout << "TONG DOANH THU TAT CA      : " << tongDoanhThu           << "\n";
    cout << "===========================================\n";

    return 0;
}