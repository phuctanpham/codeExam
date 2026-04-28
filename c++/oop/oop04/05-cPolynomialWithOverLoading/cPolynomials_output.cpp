/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

ostream& operator<<(ostream& os, const cPolynomials& ps) {
    for (int i = 0; i < ps.n; ++i) {
        os << "P" << i + 1 << "(x) = " << ps.arr[i] << "\n";
    }
    return os;
}