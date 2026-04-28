/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexNumber.h"

// OVERLOADING toan tu >> cho day so phuc (Chong nhap sai so luong)
istream& operator>>(istream& is, cComplexes& cs) {
    string line;
    while (true) {
        cout << "Nhap so luong so phuc: ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int size;
        string extra;

        // Kiem tra phai la 1 so nguyen duong don le
        if (ss >> size && size > 0 && !(ss >> extra)) {
            cs.n = size;
            break;
        }
        cout << "Loi: So luong phai la so nguyen duong. Vui long nhap lai.\n";
    }

    if (cs.arr != nullptr) delete[] cs.arr;
    cs.arr = new cComplex[cs.n];

    for (int i = 0; i < cs.n; ++i) {
        cout << "Nhap so phuc thu " << i + 1 << " (thuc ao): ";
        is >> cs.arr[i]; // Goi toan tu >> cua cComplex da duoc kiem soat loi
    }
    return is;
}