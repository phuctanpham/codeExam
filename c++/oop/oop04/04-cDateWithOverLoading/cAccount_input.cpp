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
        cout << "Nhap so tien gui (VND, vi du: 10000000): " << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        double tien;
        string extra;
        if (ss >> tien && tien > 0 && !(ss >> extra)) {
            acc.soTienGui = tien;
            break;
        }
        cout << "  Loi: So tien gui phai la so duong. Vui long nhap lai." << endl;
    }

    // 2. Nhap va kiem tra Lai suat
    while (true) {
        cout << "Nhap lai suat nam (%, vi du: 7.5): " << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        double lai;
        string extra;
        if (ss >> lai && lai >= 0 && !(ss >> extra)) {
            acc.laiSuatNam = lai;
            break;
        }
        cout << "  Loi: Lai suat phai >= 0. Vui long nhap lai." << endl;
    }

    // 3. Nhap Ngay gui va Ngay rut
    // [SUA] Xoa bo 2 lenh is.ignore(256, '\n') sau moi lan goi operator>> cua cDate.
    //       Nguyen nhan: operator>> cua cDate dung getline() ben trong nen '\n' da duoc
    //       tieu thu san. Goi them is.ignore() se xoa mat dong du lieu tiep theo
    //       (tuc la ngay rut hoac ngay gui vong lap sau), gay ra vong lap vo han.
    while (true) {
        cout << "\n--- Nhap Ngay Gui ---" << endl;
        is >> acc.ngayGui;

        cout << "\n--- Nhap Ngay Rut ---" << endl;
        is >> acc.ngayRut;

        if (acc.ngayRut > acc.ngayGui) {
            break;
        }
        cout << "\n  [!] LOI: Ngay rut phai sau ngay gui. Vui long nhap lai ca hai!" << endl;
    }

    return is;
}
