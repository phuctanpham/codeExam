/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử >> cho phép nhập cả dãy
istream& operator>>(istream& is, cFractions& fs) {
    cout << "Nhap so luong phan so: ";
    is >> fs.n;
    if (fs.arr != nullptr) delete[] fs.arr;
    fs.arr = new cFraction[fs.n];
    
    for (int i = 0; i < fs.n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << " (tu mau): ";
        is >> fs.arr[i]; // Tận dụng OVERLOADING >> của cFraction
    }
    return is;
}