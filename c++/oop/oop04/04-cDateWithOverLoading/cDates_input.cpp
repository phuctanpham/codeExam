/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// OVERLOADING toan tu >> cho day ngay thang
// [SUA] Xoa prompt "Dinh dang..." khoi day vi operator>> cua cDate da tu hien thi
//        huong dan truoc moi lan nhap. Giu prompt "--- Nhap moc thu i ---" cho ro cau truc.
istream& operator>>(istream& is, cDates& ds) {
    string line;
    while (true) {
        cout << "Nhap so luong moc thoi gian (vi du: 3):" << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int size;
        string extra;
        if (ss >> size && size > 0 && !(ss >> extra)) {
            ds.n = size;
            break;
        }
        cout << "  Loi: So luong phai la so nguyen duong. Vui long nhap lai." << endl;
    }

    if (ds.arr != nullptr) delete[] ds.arr;
    ds.arr = new cDate[ds.n];

    for (int i = 0; i < ds.n; ++i) {
        cout << "--- Nhap moc thoi gian thu " << i + 1 << " ---" << endl;
        is >> ds.arr[i]; // operator>> cua cDate tu hien thi huong dan
    }
    return is;
}
