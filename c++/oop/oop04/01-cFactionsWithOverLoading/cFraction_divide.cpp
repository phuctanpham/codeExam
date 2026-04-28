/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

// OVERLOADING toán tử / chia 2 phân số
// [SỬA 1] Thêm 'const' ở cuối hàm: phép chia không thay đổi đối tượng đang gọi
// [SỬA 2] Kiểm tra chia cho 0: nếu tử số của 'other' bằng 0 thì không thể chia,
//          trước đây constructor âm thầm đặt mẫu=1 gây ra kết quả sai mà không báo lỗi
cFraction cFraction::operator/(const cFraction& other) const {
    if (other.tu == 0) {
        cerr << "Loi: Khong the chia cho phan so 0!" << endl;
        return cFraction(0, 1); // Trả về 0 an toàn thay vì crash
    }
    return cFraction(tu * other.mau, mau * other.tu);
}
