#include <iostream>
#include <string>

using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    string gioiTinh;
    int ngay, thang, namSinh;

public:
    void nhapThongTin() {
        cout << "Nhap ma nhan vien: ";
        getline(cin >> ws, maNV); 
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
        cout << "Nhap ngay, thang, nam sinh: ";
        cin >> ngay >> thang >> namSinh;
    }

    void xuatThongTin() const {
        cout << "Ma NV: " << maNV << " | Ten: " << hoTen 
             << " | Gioi tinh: " << gioiTinh 
             << " | NS: " << ngay << "/" << thang << "/" << namSinh << endl;
    }

    bool treHon(const NhanVien& nvKhac) const {
        if (namSinh > nvKhac.namSinh) return true;
        if (namSinh < nvKhac.namSinh) return false;
        
        if (thang > nvKhac.thang) return true;
        if (thang < nvKhac.thang) return false;
        
        return ngay > nvKhac.ngay;
    }
};