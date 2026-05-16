/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBatDongSan_RealEstate.h"
#include <vector>

int main() {
    int nDat, nNhaPho, nChungCu;
    vector<GiaoDichDat> dsDat;
    vector<GiaoDichNhaPho> dsNhaPho;
    vector<GiaoDichChungCu> dsChungCu;
    vector<GiaoDichBDS*> dsTongHop;

    // 1. Nhap danh sach 
    cout << "=== NHAP DANH SACH GIAO DICH DAT ===\n";
    cout << "So luong: "; cin >> nDat; cin.ignore();
    for (int i = 0; i < nDat; i++) {
        GiaoDichDat gd; cin >> gd;
        dsDat.push_back(gd);
        dsTongHop.push_back(&dsDat.back());
    }

    cout << "\n=== NHAP DANH SACH GIAO DICH NHA PHO ===\n";
    cout << "So luong: "; cin >> nNhaPho; cin.ignore();
    for (int i = 0; i < nNhaPho; i++) {
        GiaoDichNhaPho gd; cin >> gd;
        dsNhaPho.push_back(gd);
        dsTongHop.push_back(&dsNhaPho.back());
    }

    cout << "\n=== NHAP DANH SACH GIAO DICH CHUNG CU ===\n";
    cout << "So luong: "; cin >> nChungCu; cin.ignore();
    for (int i = 0; i < nChungCu; i++) {
        GiaoDichChungCu gd; cin >> gd;
        dsChungCu.push_back(gd);
        dsTongHop.push_back(&dsChungCu.back());
    }

    // 2. Tinh tong so luong cho tung loai [cite: 74]
    cout << "\n===========================================\n";
    cout << "TONG SO LUONG GIAO DICH DAT      : " << dsDat.size() << "\n";
    cout << "TONG SO LUONG GIAO DICH NHA PHO  : " << dsNhaPho.size() << "\n";
    cout << "TONG SO LUONG GIAO DICH CHUNG CU : " << dsChungCu.size() << "\n";

    // 3. Tinh trung binh thanh tien cua giao dich Chung cu 
    double tongTienChungCu = 0;
    for (const auto& gd : dsChungCu) {
        tongTienChungCu += gd.tinhThanhTien();
    }
    double tbChungCu = (dsChungCu.empty()) ? 0 : tongTienChungCu / dsChungCu.size();
    cout << "TRUNG BINH THANH TIEN CHUNG CU   : " << fixed << setprecision(0) << tbChungCu << "\n";

    // 4. Cho biet Giao dich Nha pho co tri gia cao nhat 
    cout << "\n=== GIAO DICH NHA PHO CO TRI GIA CAO NHAT ===\n";
    if (!dsNhaPho.empty()) {
        double maxNhaPho = -1.0;
        GiaoDichNhaPho* bestNhaPho = nullptr;
        for (auto& gd : dsNhaPho) {
            if (gd.tinhThanhTien() > maxNhaPho) {
                maxNhaPho = gd.tinhThanhTien();
                bestNhaPho = &gd;
            }
        }
        cout << *bestNhaPho;
    } else {
        cout << "Khong co giao dich nha pho nao.\n";
    }

    // 5. Xuat danh sach giao dich cua thang 12 nam 2024 
    cout << "\n=== CAC GIAO DICH THANG 12 NAM 2024 ===\n";
    bool foundDate = false;
    for (const auto* gd : dsTongHop) {
        // Checking if the date contains "/12/2024"
        if (gd->getNgayGiaoDich().find("/12/2024") != string::npos) {
            cout << *gd;
            foundDate = true;
        }
    }
    if (!foundDate) {
        cout << "Khong co giao dich nao trong thang 12/2024.\n";
    }

    return 0;
}