/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// [SUA] Hien thi huong dan va vi du ngay tu lan nhap dau tien (khong chi khi nhap sai),
//       giup nguoi dung biet dinh dang ma khong can phai thu sai truoc.
//       Dong thoi kiem tra day du: nam > 0, thang 1-12, ngay hop le theo thang va nam nhuan.
istream& operator>>(istream& is, cDate& d) {
    string line;
    while (true) {
        cout << "  (Vi du: 25 12 2026 la ngay 25/12/2026)" << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int ng, th, nm;
        string extra;

        if (!(ss >> ng >> th >> nm) || (ss >> extra)) {
            cout << "  Loi: Phai nhap dung 3 so nguyen cach nhau khoang trang. Vui long nhap lai." << endl;
            continue;
        }
        if (nm <= 0) {
            cout << "  Loi: Nam phai lon hon 0. Vui long nhap lai." << endl;
            continue;
        }
        if (th < 1 || th > 12) {
            cout << "  Loi: Thang phai trong khoang 1-12. Vui long nhap lai." << endl;
            continue;
        }
        // Gan tam thang va nam de goi daysInMonth() chinh xac (co tinh den nam nhuan)
        d.thang = th;
        d.nam   = nm;
        if (ng < 1 || ng > d.daysInMonth()) {
            cout << "  Loi: Ngay khong hop le voi thang " << th
                 << " nam " << nm << " (toi da " << d.daysInMonth() << " ngay). Vui long nhap lai." << endl;
            continue;
        }
        d.ngay = ng;
        break;
    }
    return is;
}
