/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudents_student.h"
#include <vector>

int main() {
    int nDH, nCD;
    vector<SinhVienDaiHoc> dsDaiHoc;
    vector<SinhVienCaoDang> dsCaoDang;
    vector<SinhVien*> dsTongHop; // Using pointers for polymorphic iteration

    // 1. Nhap danh sach sinh vien [cite: 11]
    cout << "=== NHAP DANH SACH SINH VIEN DAI HOC ===\n";
    cout << "So luong SV Dai Hoc: "; cin >> nDH; cin.ignore();
    for (int i = 0; i < nDH; i++) {
        SinhVienDaiHoc sv;
        cin >> sv; // Trigger overloaded >>
        dsDaiHoc.push_back(sv);
        dsTongHop.push_back(&dsDaiHoc.back());
    }

    cout << "\n=== NHAP DANH SACH SINH VIEN CAO DANG ===\n";
    cout << "So luong SV Cao Dang: "; cin >> nCD; cin.ignore();
    for (int i = 0; i < nCD; i++) {
        SinhVienCaoDang sv;
        cin >> sv; // Trigger overloaded >>
        dsCaoDang.push_back(sv);
        dsTongHop.push_back(&dsCaoDang.back());
    }

    // 2. Xuat danh sach sinh vien [cite: 12]
    cout << "\n=== DANH SACH TAT CA SINH VIEN ===\n";
    for (const auto* sv : dsTongHop) {
        cout << *sv; // Trigger overloaded <<
    }

    // 3 & 4. Xuat sinh vien du / khong du dieu kien [cite: 13, 14]
    cout << "\n=== SINH VIEN DU DIEU KIEN TOT NGHIEP ===\n";
    for (const auto* sv : dsTongHop) {
        if (sv->checkTotNghiep()) cout << *sv;
    }

    cout << "\n=== SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===\n";
    for (const auto* sv : dsTongHop) {
        if (!sv->checkTotNghiep()) cout << *sv;
    }

    // 5. Sinh vien dai hoc diem TB cao nhat [cite: 15]
    if (!dsDaiHoc.empty()) {
        float maxGPA = -1.0f;
        SinhVienDaiHoc* bestSV = nullptr;

        for (auto& sv : dsDaiHoc) {
            if (sv.getDiemTrungBinh() > maxGPA) {
                maxGPA = sv.getDiemTrungBinh();
                bestSV = &sv;
            }
        }
        cout << "\n=== SINH VIEN DAI HOC CO DTB CAO NHAT ===\n";
        if (bestSV) cout << *bestSV;
    }

    return 0;
}