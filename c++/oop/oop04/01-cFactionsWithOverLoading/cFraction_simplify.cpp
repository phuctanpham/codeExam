/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"
#include <cmath>

void cFraction::simplify() {
    int a = abs(tu);
    int b = abs(mau);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    tu /= a;
    mau /= a;
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}