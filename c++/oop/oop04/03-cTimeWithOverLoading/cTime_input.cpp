/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [SUA] Bo sung 2 viec:
//  1. Hien thi huong dan vi du ngay tu lan nhap dau tien (khong chi khi nhap sai)
//  2. Kiem tra pham vi hop le: gio 0-23, phut 0-59, giay 0-59
//     Truoc day chi kiem tra >= 0, nen nhap "25 70 80" van duoc chap nhan
istream& operator>>(istream& is, CTime& t) {
    string line;
    while (true) {
        cout << "  (Vi du: 10 30 45 la thoi diem 10:30:45 | gio: 0-23, phut: 0-59, giay: 0-59)" << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int h, m, s;
        string extra;

        if (!(ss >> h >> m >> s) || (ss >> extra)) {
            cout << "  Loi: Phai nhap dung 3 so nguyen cach nhau khoang trang. Vui long nhap lai." << endl;
            continue;
        }
        if (h < 0 || h > 23) {
            cout << "  Loi: Gio phai trong khoang 0-23. Vui long nhap lai." << endl;
            continue;
        }
        if (m < 0 || m > 59) {
            cout << "  Loi: Phut phai trong khoang 0-59. Vui long nhap lai." << endl;
            continue;
        }
        if (s < 0 || s > 59) {
            cout << "  Loi: Giay phai trong khoang 0-59. Vui long nhap lai." << endl;
            continue;
        }
        t.gio = h; t.phut = m; t.giay = s;
        t.chuanHoa();
        break;
    }
    return is;
}
