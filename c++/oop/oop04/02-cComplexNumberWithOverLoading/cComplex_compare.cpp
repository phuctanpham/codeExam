/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"
#include <cmath>

// [SỬA] Dùng ngưỡng epsilon thay vì so sánh == trực tiếp với số thực (float/double):
//        So sánh == với float dễ sai do sai số dấu phẩy động (floating-point precision),
//        ví dụ: 0.1 + 0.2 != 0.3 dù về mặt toán học là bằng nhau.
static const float EPSILON = 1e-6f;

bool cComplex::operator==(const cComplex& other) const {
    return (fabs(thuc - other.thuc) < EPSILON &&
            fabs(ao   - other.ao)   < EPSILON);
}

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
