/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

istream& operator>>(istream& is, cDate& d) {
    string line;
    while (true) {
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int ng, th, nm;
        string extra;

        if (ss >> ng >> th >> nm && !(ss >> extra)) {
            if (nm > 0 && th >= 1 && th <= 12) {
                d.nam = nm;
                d.thang = th; // Gan tam de check daysInMonth
                
                if (ng >= 1 && ng <= d.daysInMonth()) {
                    d.ngay = ng;
                    break;
                }
            }
        }
        cout << "Loi: Thoi gian khong hop le (chu y nam nhuan va so ngay toi da cua thang)." << endl;
        cout << "Vui long nhap lai (Vi du: 25 12 2026): ";
    }
    return is;
}