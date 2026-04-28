/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

// OVERLOADING toan tu >> cho day so phuc (Chong nhap sai so luong)
// [SỬA] Thêm hướng dẫn ví dụ khi nhập số lượng ngay từ đầu (không chỉ khi nhập sai)
istream& operator>>(istream& is, cComplexes& cs) {
    string line;
    while (true) {
        cout << "Nhap so luong so phuc (vi du: 3):" << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int size;
        string extra;

        if (ss >> size && size > 0 && !(ss >> extra)) {
            cs.n = size;
            break;
        }
        cout << "  Loi: Phai la so nguyen duong lon hon 0. Vui long nhap lai." << endl;
    }

    if (cs.arr != nullptr) delete[] cs.arr;
    cs.arr = new cComplex[cs.n];

    for (int i = 0; i < cs.n; ++i) {
        cout << "Nhap so phuc thu " << i + 1 << ":" << endl;
        is >> cs.arr[i];
    }
    return is;
}
