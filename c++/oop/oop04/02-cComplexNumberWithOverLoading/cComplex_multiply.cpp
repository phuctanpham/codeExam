/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

cComplex cComplex::operator*(const cComplex& other) const {
    float t = thuc * other.thuc - ao * other.ao;
    float a = thuc * other.ao + ao * other.thuc;
    return cComplex(t, a);
}