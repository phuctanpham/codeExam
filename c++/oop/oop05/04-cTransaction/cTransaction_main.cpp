/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cGiaoDich_Transaction.h"
#include <vector>

int main() {
    int nVang, nTienTe;
    vector<GiaoDichVang> dsVang;
    vector<GiaoDichTienTe> dsTienTe;
    vector<GiaoDich*> dsTongHop;

    // 1. Nhap danh sach
    cout << "=== NHAP DANH SACH GIAO DICH VANG ===\n";
    cout << "So luong GD Vang: "; cin >> nVang; cin.ignore();
    for (int i = 0; i < nVang; i++) {
        cout << "--- GD Vang thu " << i + 1 << " ---\n";
        GiaoDichVang gd;
        cin >> gd;
        dsVang.push_back(gd);
        dsTongHop.push_back(&dsVang.back());
    }

    cout << "\n=== NHAP DANH SACH GIAO DICH TIEN TE ===\n";
    cout << "So luong GD Tien Te: "; cin >> nTienTe; cin.ignore();
    for (int i = 0; i < nTienTe; i++) {
        cout << "--- GD Tien te thu " << i + 1 << " ---\n";
        GiaoDichTienTe gd;
        cin >> gd;
        dsTienTe.push_back(gd);
        dsTongHop.push_back(&dsTienTe.back());
    }

    // 2. Giao dich vang co thanh tien cao nhat
    cout << "\n===========================================\n";
    if (!dsVang.empty()) {
        double maxThanhTienVang = -1.0;
        GiaoDichVang* bestVang = nullptr;
        for (auto& gd : dsVang) {
            if (gd.tinhThanhTien() > maxThanhTienVang) {
                maxThanhTienVang = gd.tinhThanhTien();
                bestVang = &gd;
            }
        }
        cout << "=== GIAO DICH VANG CO THANH TIEN CAO NHAT ===\n";
        cout << *bestVang;
    }

    // 3. Giao dich Euro co thanh tien thap nhat
    cout << "\n=== GIAO DICH EURO CO THANH TIEN THAP NHAT ===\n";
    double minThanhTienEuro = -1.0;
    GiaoDichTienTe* worstEuro = nullptr;
    for (auto& gd : dsTienTe) {
        if (gd.getLoaiTienTe() == "Euro") {
            if (minThanhTienEuro == -1.0 || gd.tinhThanhTien() < minThanhTienEuro) {
                minThanhTienEuro = gd.tinhThanhTien();
                worstEuro = &gd;
            }
        }
    }
    
    if (worstEuro) {
        cout << *worstEuro;
    } else {
        cout << "Khong co giao dich Euro nao!\n";
    }

    // 4. Giao dich tren 1 ty dong
    cout << "\n=== CAC GIAO DICH CO THANH TIEN > 1 TY DONG ===\n";
    bool foundBillion = false;
    for (const auto* gd : dsTongHop) {
        if (gd->tinhThanhTien() > 1000000000.0) {
            cout << *gd;
            foundBillion = true;
        }
    }
    if (!foundBillion) {
        cout << "Khong co giao dich nao tren 1 ty dong.\n";
    }

    return 0;
}