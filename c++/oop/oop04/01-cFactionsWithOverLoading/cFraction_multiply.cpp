/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử * nhân 2 phân số
// [SỬA] Thêm 'const' ở cuối hàm: phép nhân không thay đổi đối tượng đang gọi
cFraction cFraction::operator*(const cFraction& other) const {
    return cFraction(tu * other.tu, mau * other.mau);
}
