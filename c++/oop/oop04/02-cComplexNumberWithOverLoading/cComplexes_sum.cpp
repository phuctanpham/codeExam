/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

cComplex cComplexes::sum() const {
    cComplex total(0, 0);
    for (int i = 0; i < n; ++i) {
        total = total + arr[i];
    }
    return total;
}