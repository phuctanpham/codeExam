/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexNumber.h"

// So sanh bang (cung phan thuc va phan ao)
bool cComplex::operator==(const cComplex& other) const {
    return (thuc == other.thuc && ao == other.ao);
}

// So sanh khac
bool cComplex::operator!=(const cComplex& other) const {
    return !(*this == other);
}

// So sanh lon hon dua vao Modulus
bool cComplex::operator>(const cComplex& other) const {
    return this->modulus() > other.modulus();
}

// So sanh nho hon dua vao Modulus
bool cComplex::operator<(const cComplex& other) const {
    return this->modulus() < other.modulus();
}