/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"

istream& operator>>(istream& is, CTime& t) {
    string line;
    while (true) {
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int h, m, s;
        string extra;

        if (ss >> h >> m >> s && !(ss >> extra)) {
            if (h >= 0 && m >= 0 && s >= 0) {
                t.gio = h;
                t.phut = m;
                t.giay = s;
                t.chuanHoa();
                break;
            } else {
                cout << "Loi: Thoi gian khong duoc chua so am. Vui long nhap lai (hh mm ss): ";
                continue;
            }
        }
        cout << "Loi: Nhap sai dinh dang. Vui long nhap dung 3 so (hh mm ss): ";
    }
    return is;
}