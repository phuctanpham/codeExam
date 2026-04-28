/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// OVERLOADING toan tu >> cho day ngay thang
istream& operator>>(istream& is, cDates& ds) {
    string line;
    while (true) {
        cout << "Nhap so luong moc thoi gian (n > 0): ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int size;
        string extra;

        if (ss >> size && size > 0 && !(ss >> extra)) {
            ds.n = size;
            break;
        }
        cout << "Loi: So luong phai la so nguyen duong. Vui long nhap lai.\n";
    }

    // Cap phat lai mang
    if (ds.arr != nullptr) delete[] ds.arr;
    ds.arr = new cDate[ds.n];

    for (int i = 0; i < ds.n; ++i) {
        cout << "--- Nhap moc thoi gian thu " << i + 1 << " ---\n";
        cout << "Dinh dang (ngay thang nam), Vi du: 25 12 2026: ";
        is >> ds.arr[i]; // Goi operator>> cua cDate da co chong nhap sai
    }
    return is;
}