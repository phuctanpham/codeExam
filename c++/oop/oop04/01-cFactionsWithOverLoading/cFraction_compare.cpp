/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử == so sánh bằng
bool cFraction::operator==(const cFraction& other) {
    return (tu * other.mau == other.tu * mau);
}

// OVERLOADING toán tử > so sánh lớn hơn
bool cFraction::operator>(const cFraction& other) {
    return (tu * other.mau > other.tu * mau);
}

// OVERLOADING toán tử < so sánh nhỏ hơn
bool cFraction::operator<(const cFraction& other) {
    return (tu * other.mau < other.tu * mau);
}