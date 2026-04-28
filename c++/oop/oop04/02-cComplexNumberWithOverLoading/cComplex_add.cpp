/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

cComplex cComplex::operator+(const cComplex& other) const {
    return cComplex(thuc + other.thuc, ao + other.ao);
}