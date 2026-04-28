/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử + cộng 2 phân số
// [SỬA] Thêm 'const' ở cuối hàm: phép cộng không thay đổi đối tượng đang gọi
cFraction cFraction::operator+(const cFraction& other) const {
    int t = tu * other.mau + other.tu * mau;
    int m = mau * other.mau;
    return cFraction(t, m); // Constructor sẽ tự động rút gọn
}
