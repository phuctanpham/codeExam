/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// [SỬA] Thêm 'const': hàm sum() chỉ đọc mảng, không thay đổi dữ liệu
cFraction cFractions::sum() const {
    cFraction total(0, 1);
    for (int i = 0; i < n; ++i) {
        total = total + arr[i]; // Tận dụng OVERLOADING +
    }
    return total;
}
