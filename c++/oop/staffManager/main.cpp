#include <iostream>
#include "staff.cpp" 

using namespace std;

int main() {
    NhanVien nv1, nv2;

    cout << "--- NHAP THONG TIN NHAN VIEN 1 ---\n";
    nv1.nhapThongTin();
    
    cout << "\n--- NHAP THONG TIN NHAN VIEN 2 ---\n";
    nv2.nhapThongTin();

    cout << "\n--- NHAN VIEN CO TUOI NHO HON ---\n";
    
    if (nv1.treHon(nv2)) {
        nv1.xuatThongTin();
    } else if (nv2.treHon(nv1)) {
        nv2.xuatThongTin();
    } else {
        cout << "Hai nhan vien co cung ngay thang nam sinh.\n";
    }

    return 0;
}