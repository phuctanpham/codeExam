/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

// [SỬA] Bổ sung xử lý các trường hợp đặc biệt khi in:
//        - Nếu ao == 0: chỉ in phần thực (ví dụ: "5" thay vì "5 + 0i")
//        - Nếu thuc == 0: chỉ in phần ảo (ví dụ: "3i" thay vì "0 + 3i")
//        - Nếu cả hai == 0: in "0"
ostream& operator<<(ostream& os, const cComplex& c) {
    bool hasThuc = (c.thuc != 0);
    bool hasAo   = (c.ao != 0);

    if (!hasThuc && !hasAo) {
        os << "0";
    } else if (!hasAo) {
        os << c.thuc;
    } else if (!hasThuc) {
        if (c.ao == 1)       os << "i";
        else if (c.ao == -1) os << "-i";
        else                 os << c.ao << "i";
    } else {
        os << c.thuc;
        if (c.ao >= 0) os << " + " << c.ao << "i";
        else           os << " - " << -c.ao << "i";
    }
    return os;
}
