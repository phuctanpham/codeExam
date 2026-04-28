/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"
#include <sstream>
#include <string>

// OVERLOADING toán tử >> cho phép nhập cả dãy
// [SỬA] Dùng getline để đọc số lượng, kiểm tra phải là số nguyên dương > 0
//        -> tránh treo khi nhập chữ hoặc số âm
istream& operator>>(istream& is, cFractions& fs) {
    string line;
    if (is.peek() == '\n') is.ignore();

    while (true) {
        cout << "Nhap so luong phan so (vi du: 3):" << endl;
        cout << "  >> ";
        getline(is, line);

        istringstream iss(line);
        int n;
        char extra;

        if (!(iss >> n)) {
            cout << "  Loi: Phai nhap so nguyen duong!" << endl;
        } else if (iss >> extra) {
            cout << "  Loi: Chi nhap dung 1 so nguyen duong!" << endl;
        } else if (n <= 0) {
            cout << "  Loi: So luong phan so phai lon hon 0!" << endl;
        } else {
            fs.n = n;
            break;
        }
        cout << "  Vui long nhap lai." << endl;
    }

    if (fs.arr != nullptr) delete[] fs.arr;
    fs.arr = new cFraction[fs.n];

    for (int i = 0; i < fs.n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":" << endl;
        is >> fs.arr[i]; // Tận dụng OVERLOADING >> của cFraction
    }
    return is;
}
