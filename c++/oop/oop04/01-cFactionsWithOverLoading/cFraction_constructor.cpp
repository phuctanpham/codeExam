/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

cFraction::cFraction(int t, int m) {
    tu = t;
    mau = (m == 0) ? 1 : m;
    simplify();
}