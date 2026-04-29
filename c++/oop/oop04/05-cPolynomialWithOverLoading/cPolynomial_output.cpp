/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// In da thuc toi uu: khong in he so 0, in "x" thay vi "x^1", dau +/- dep
// [SUA] Dung fabs() thay vi abs() de dam bao lay gia tri tuyet doi dung cho kieu double.
//        abs() trong C la ham cho kieu int, co the cat ngat phan thap phan neu
//        compiler khong resolve dung sang std::abs tu <cmath>.
ostream& operator<<(ostream& os, const cPolynomial& p) {
    bool isAllZero = true;

    for (int i = p.bac; i >= 0; --i) {
        if (fabs(p.heSo[i]) < 1e-9) continue; // [SUA] dung nguong thay vi == 0

        if (isAllZero) {
            if (p.heSo[i] < 0) os << "-";
        } else {
            os << (p.heSo[i] > 0 ? " + " : " - ");
        }

        double absVal = fabs(p.heSo[i]); // [SUA] fabs() ro rang cho double

        if (absVal != 1.0 || i == 0) {
            os << absVal;
        }

        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;

        isAllZero = false;
    }

    if (isAllZero) os << "0";
    return os;
}
