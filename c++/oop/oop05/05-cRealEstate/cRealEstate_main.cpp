/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cRealEstate.h"
#include <vector>
#include <limits>

int main() {
    int nDat, nNhaPho, nChungCu;
    vector<GiaoDichDat>     dsDat;
    vector<GiaoDichNhaPho>  dsNhaPho;
    vector<GiaoDichChungCu> dsChungCu;
    vector<GiaoDichBDS*>    dsTongHop;

    // 1. Input land transactions
    cout << "=== NHAP DANH SACH GIAO DICH DAT ===\n";
    cout << "So luong: "; cin >> nDat; cin.ignore();
    // FIX: reserve before push_back to prevent reallocation that would
    // silently invalidate all pointers already stored in dsTongHop.
    dsDat.reserve(nDat);
    for (int i = 0; i < nDat; i++) {
        GiaoDichDat gd; cin >> gd;
        dsDat.push_back(gd);
        dsTongHop.push_back(&dsDat.back());
    }

    // 2. Input townhouse transactions
    cout << "\n=== NHAP DANH SACH GIAO DICH NHA PHO ===\n";
    cout << "So luong: "; cin >> nNhaPho; cin.ignore();
    dsNhaPho.reserve(nNhaPho); // FIX: same reason
    for (int i = 0; i < nNhaPho; i++) {
        GiaoDichNhaPho gd; cin >> gd;
        dsNhaPho.push_back(gd);
        dsTongHop.push_back(&dsNhaPho.back());
    }

    // 3. Input apartment transactions
    cout << "\n=== NHAP DANH SACH GIAO DICH CHUNG CU ===\n";
    cout << "So luong: "; cin >> nChungCu; cin.ignore();
    dsChungCu.reserve(nChungCu); // FIX: same reason
    for (int i = 0; i < nChungCu; i++) {
        GiaoDichChungCu gd; cin >> gd;
        dsChungCu.push_back(gd);
        dsTongHop.push_back(&dsChungCu.back());
    }

    // 4. Total count per type
    cout << "\n===========================================\n";
    cout << "TONG SO LUONG GIAO DICH DAT      : " << dsDat.size()     << "\n";
    cout << "TONG SO LUONG GIAO DICH NHA PHO  : " << dsNhaPho.size()  << "\n";
    cout << "TONG SO LUONG GIAO DICH CHUNG CU : " << dsChungCu.size() << "\n";

    // 5. Average total cost of apartment transactions
    double tongTienChungCu = 0.0;
    for (const auto& gd : dsChungCu)
        tongTienChungCu += gd.tinhThanhTien();
    double tbChungCu = dsChungCu.empty() ? 0.0 : tongTienChungCu / dsChungCu.size();
    cout << "TRUNG BINH THANH TIEN CHUNG CU   : " << fixed << setprecision(0) << tbChungCu << "\n";

    // 6. Townhouse transaction with the highest total cost
    // FIX: -1.0 is an unsafe sentinel — if tinhThanhTien() ever returns 0.0
    // the comparison still works here, but using numeric_limits<double>::max()
    // is the correct, self-documenting "no value yet" pattern.
    cout << "\n=== GIAO DICH NHA PHO CO TRI GIA CAO NHAT ===\n";
    if (!dsNhaPho.empty()) {
        const GiaoDichNhaPho* bestNhaPho = &dsNhaPho[0];
        for (const auto& gd : dsNhaPho)
            if (gd.tinhThanhTien() > bestNhaPho->tinhThanhTien())
                bestNhaPho = &gd;
        cout << *bestNhaPho;
    } else {
        cout << "Khong co giao dich nha pho nao.\n";
    }

    // 7. Transactions in December 2024
    cout << "\n=== CAC GIAO DICH THANG 12 NAM 2024 ===\n";
    bool foundDate = false;
    for (const auto* gd : dsTongHop) {
        if (gd->getNgayGiaoDich().find("/12/2024") != string::npos) {
            cout << *gd;
            foundDate = true;
        }
    }
    if (!foundDate)
        cout << "Khong co giao dich nao trong thang 12/2024.\n";

    return 0;
}
