/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexNumber.h"

ostream& operator<<(ostream& os, const cComplex& c) {
    os << c.thuc;
    if (c.ao >= 0) os << " + " << c.ao << "i";
    else os << " - " << -c.ao << "i";
    return os;
}