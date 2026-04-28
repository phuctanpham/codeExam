/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cAccount.h"

istream& operator>>(istream& is, cAccount& acc) {
    string line;
    
    // 1. Nhap va kiem tra So tien gui
    while (true) {
        cout << "Nhap so tien gui (VND): ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        double tien;
        string extra;
        if (ss >> tien && tien > 0 && !(ss >> extra)) {
            acc.soTienGui = tien;
            break;
        }
        cout << "Loi: So tien gui phai la so duong. Vui long nhap lai.\n";
    }

    // 2. Nhap va kiem tra Lai suat
    while (true) {
        cout << "Nhap lai suat nam (%): ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        double lai;
        string extra;
        if (ss >> lai && lai >= 0 && !(ss >> extra)) {
            acc.laiSuatNam = lai;
            break;
        }
        cout << "Loi: Lai suat phai >= 0. Vui long nhap lai.\n";
    }

    // 3. Nhap Ngay gui va Ngay rut (Dam bao tinh logic ve mat thoi gian)
    while (true) {
        cout << "\n--- Nhap thong tin Ngay Gui ---\n";
        cout << "Dinh dang (ngay thang nam), Vi du: 01 01 2026: ";
        is >> acc.ngayGui; // Tu dong goi ham chong nhap sai cua cDate
        
        // Loai bo ky tu '\n' thua sau khi nhap cDate de getline hoat dong tot o vong lap sau neu co
        is.ignore(256, '\n'); 

        cout << "\n--- Nhap thong tin Ngay Rut ---\n";
        cout << "Dinh dang (ngay thang nam), Vi du: 31 12 2026: ";
        is >> acc.ngayRut;
        is.ignore(256, '\n');

        if (acc.ngayRut > acc.ngayGui) {
            break; // Thoa man dieu kien thoi gian
        } else {
            cout << "\n[!] LOI: Ngay rut phai sau ngay gui. Vui long thiet lap lai ca 2 moc thoi gian!\n";
        }
    }

    return is;
}