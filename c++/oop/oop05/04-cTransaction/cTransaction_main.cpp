/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"
#include <vector>
#include <limits>

int main() {
    int nVang, nTienTe;
    vector<GiaoDichVang>   dsVang;
    vector<GiaoDichTienTe> dsTienTe;
    vector<GiaoDich*>      dsTongHop;

    // 1. Input gold transactions
    cout << "=== NHAP DANH SACH GIAO DICH VANG ===\n";
    cout << "So luong GD Vang: "; cin >> nVang; cin.ignore();

    // FIX: reserve before push_back so the vector never reallocates while
    // we are collecting addresses into dsTongHop (same bug as cStudent).
    dsVang.reserve(nVang);

    for (int i = 0; i < nVang; i++) {
        cout << "--- GD Vang thu " << i + 1 << " ---\n";
        GiaoDichVang gd;
        cin >> gd;
        dsVang.push_back(gd);
        dsTongHop.push_back(&dsVang.back());
    }

    // 2. Input currency transactions
    cout << "\n=== NHAP DANH SACH GIAO DICH TIEN TE ===\n";
    cout << "So luong GD Tien Te: "; cin >> nTienTe; cin.ignore();

    dsTienTe.reserve(nTienTe); // FIX: same reason

    for (int i = 0; i < nTienTe; i++) {
        cout << "--- GD Tien te thu " << i + 1 << " ---\n";
        GiaoDichTienTe gd;
        cin >> gd;
        dsTienTe.push_back(gd);
        dsTongHop.push_back(&dsTienTe.back());
    }

    // 3. Gold transaction with highest total cost
    cout << "\n===========================================\n";
    if (!dsVang.empty()) {
        const GiaoDichVang* bestVang = &dsVang[0];
        for (const auto& gd : dsVang)
            if (gd.tinhThanhTien() > bestVang->tinhThanhTien())
                bestVang = &gd;

        cout << "=== GIAO DICH VANG CO THANH TIEN CAO NHAT ===\n";
        cout << *bestVang;
    }

    // 4. Euro currency transaction with the lowest total cost
    // FIX: using -1.0 as a sentinel is fragile — a legitimate tinhThanhTien()
    // can return 0.0, which would compare less than -1.0 is never triggered,
    // but using numeric_limits<double>::max() as the initial "no value" guard
    // is the correct pattern.
    cout << "\n=== GIAO DICH EURO CO THANH TIEN THAP NHAT ===\n";
    double minThanhTienEuro        = numeric_limits<double>::max();
    const GiaoDichTienTe* worstEuro = nullptr;

    for (const auto& gd : dsTienTe) {
        if (gd.getLoaiTienTe() == "Euro" && gd.tinhThanhTien() < minThanhTienEuro) {
            minThanhTienEuro = gd.tinhThanhTien();
            worstEuro = &gd;
        }
    }

    if (worstEuro)
        cout << *worstEuro;
    else
        cout << "Khong co giao dich Euro nao!\n";

    // 5. Transactions with total cost over 1 billion VND
    cout << "\n=== CAC GIAO DICH CO THANH TIEN > 1 TY DONG ===\n";
    bool foundBillion = false;
    for (const auto* gd : dsTongHop) {
        if (gd->tinhThanhTien() > 1'000'000'000.0) {
            cout << *gd;
            foundBillion = true;
        }
    }
    if (!foundBillion)
        cout << "Khong co giao dich nao tren 1 ty dong.\n";

    return 0;
}
