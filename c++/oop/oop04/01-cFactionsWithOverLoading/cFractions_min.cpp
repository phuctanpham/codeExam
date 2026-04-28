/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// [SỬA] Thêm 'const': hàm min() chỉ đọc mảng, không thay đổi dữ liệu
cFraction cFractions::min() const {
    if (n == 0) return cFraction(0, 1);
    cFraction minValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minValue) { // Tận dụng OVERLOADING <
            minValue = arr[i];
        }
    }
    return minValue;
}
