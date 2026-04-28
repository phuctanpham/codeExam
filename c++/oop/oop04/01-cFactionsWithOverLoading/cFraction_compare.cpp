/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử == so sánh bằng
// [SỬA] Thêm 'const': phép so sánh chỉ đọc dữ liệu, không thay đổi đối tượng
// Dùng nhân chéo (tu1*mau2 == tu2*mau1) thay vì chia để tránh số thực
bool cFraction::operator==(const cFraction& other) const {
    return (tu * other.mau == other.tu * mau);
}

// OVERLOADING toán tử > so sánh lớn hơn
// [SỬA] Thêm 'const': phép so sánh chỉ đọc dữ liệu, không thay đổi đối tượng
// Lưu ý: simplify() đảm bảo mau luôn dương nên nhân chéo cho kết quả đúng
bool cFraction::operator>(const cFraction& other) const {
    return (tu * other.mau > other.tu * mau);
}

// OVERLOADING toán tử < so sánh nhỏ hơn
// [SỬA] Thêm 'const': phép so sánh chỉ đọc dữ liệu, không thay đổi đối tượng
bool cFraction::operator<(const cFraction& other) const {
    return (tu * other.mau < other.tu * mau);
}
