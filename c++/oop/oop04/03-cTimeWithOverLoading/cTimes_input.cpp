/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Overloading >> cho day thoi diem, kiem tra so luong phai > 0
istream& operator>>(istream& is, cTimes& ts) {
    string line;
    while (true) {
        cout << "Nhap so luong thoi diem (vi du: 3):" << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int size;
        string extra;
        if (ss >> size && size > 0 && !(ss >> extra)) {
            ts.n = size;
            break;
        }
        cout << "  Loi: Phai la so nguyen duong lon hon 0. Vui long nhap lai." << endl;
    }

    delete[] ts.arr;
    ts.arr = new CTime[ts.n];
    for (int i = 0; i < ts.n; ++i) {
        cout << "Nhap thoi diem thu " << i + 1 << ":" << endl;
        is >> ts.arr[i]; // Tan dung OVERLOADING >> cua CTime (co kiem tra hop le)
    }
    return is;
}
