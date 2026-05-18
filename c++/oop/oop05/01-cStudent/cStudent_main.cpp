/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudent.h"   // FIX: was "cStudents_student.h" — wrong filename
#include <vector>

int main() {
    int nDH, nCD;
    vector<SinhVienDaiHoc>  dsDaiHoc;
    vector<SinhVienCaoDang> dsCaoDang;
    vector<SinhVien*>       dsTongHop; // raw pointers for polymorphic iteration

    // ----------------------------------------------------------------
    // 1. Input university students
    // ----------------------------------------------------------------
    cout << "=== NHAP DANH SACH SINH VIEN DAI HOC ===\n";
    cout << "So luong SV Dai Hoc: "; cin >> nDH; cin.ignore();

    // FIX: reserve() before any push_back so the vector never reallocates
    // while we are collecting addresses into dsTongHop.
    // Without reserve(), each push_back that triggers a reallocation
    // silently invalidates every pointer already stored in dsTongHop.
    dsDaiHoc.reserve(nDH);

    for (int i = 0; i < nDH; i++) {
        SinhVienDaiHoc sv;
        cin >> sv;                              // calls overloaded >> -> virtual inputInfo()
        dsDaiHoc.push_back(sv);
        dsTongHop.push_back(&dsDaiHoc.back()); // safe: no reallocation possible after reserve
    }

    // ----------------------------------------------------------------
    // 2. Input college students
    // ----------------------------------------------------------------
    cout << "\n=== NHAP DANH SACH SINH VIEN CAO DANG ===\n";
    cout << "So luong SV Cao Dang: "; cin >> nCD; cin.ignore();

    dsCaoDang.reserve(nCD); // FIX: same reason as above

    for (int i = 0; i < nCD; i++) {
        SinhVienCaoDang sv;
        cin >> sv;
        dsCaoDang.push_back(sv);
        dsTongHop.push_back(&dsCaoDang.back());
    }

    // ----------------------------------------------------------------
    // 3. Output all students
    // ----------------------------------------------------------------
    cout << "\n=== DANH SACH TAT CA SINH VIEN ===\n";
    for (const auto* sv : dsTongHop)
        cout << *sv; // calls overloaded << -> virtual displayInfo()

    // ----------------------------------------------------------------
    // 4. Output students eligible for graduation
    // ----------------------------------------------------------------
    cout << "\n=== SINH VIEN DU DIEU KIEN TOT NGHIEP ===\n";
    for (const auto* sv : dsTongHop)
        if (sv->checkTotNghiep()) cout << *sv;

    // ----------------------------------------------------------------
    // 5. Output students NOT eligible for graduation
    // ----------------------------------------------------------------
    cout << "\n=== SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===\n";
    for (const auto* sv : dsTongHop)
        if (!sv->checkTotNghiep()) cout << *sv;

    // ----------------------------------------------------------------
    // 6. University student with the highest GPA
    // ----------------------------------------------------------------
    if (!dsDaiHoc.empty()) {
        const SinhVienDaiHoc* bestSV = &dsDaiHoc[0];
        for (const auto& sv : dsDaiHoc)
            if (sv.getDiemTrungBinh() > bestSV->getDiemTrungBinh())
                bestSV = &sv;

        cout << "\n=== SINH VIEN DAI HOC CO DTB CAO NHAT ===\n";
        cout << *bestSV;
    }

    return 0;
}