/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

cFractions::cFractions(int size) {
    n = size;
    if (n > 0) arr = new cFraction[n];
    else arr = nullptr;
}