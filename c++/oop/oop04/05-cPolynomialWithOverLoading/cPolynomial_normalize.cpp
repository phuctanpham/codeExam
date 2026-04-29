/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// [THEM MOI] Ham chuan hoa bac da thuc sau phep tinh
// Van de: sau phep cong/tru, he so bac cao nhat co the bang 0
//         lam cho "bac" noi bo sai so voi bac toan hoc thuc su.
// Vi du: (x^2 + 1) + (-x^2 + 2) → heSo = [3, 0, 0], bac = 2
//        nhung ve toan hoc ket qua la hang so 3 (bac = 0).
//        Neu khong chuan hoa, so sanh > / < se cho ket qua sai
//        vi no uu tien bac truoc.
// Giai phap: giam bac cho den khi heSo[bac] != 0 hoac bac = 0
void cPolynomial::normalize() {
    static const double EPSILON = 1e-9;
    while (bac > 0 && fabs(heSo[bac]) < EPSILON) {
        bac--;
    }
    // Luu y: khong can cap phat lai mang vi destructor delete[] toan bo
    // Vung nho du thua (chi so > bac moi) se khong bao gio duoc truy cap
}
