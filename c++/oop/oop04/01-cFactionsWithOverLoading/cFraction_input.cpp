/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"
#include <sstream>
#include <string>

// OVERLOADING toán tử >> dùng để nhập phân số
// [SỬA] Dùng getline đọc cả dòng trước, sau đó mới parse 2 số
//        -> tránh bị treo khi người dùng nhập thiếu số hoặc sai định dạng
istream& operator>>(istream& is, cFraction& f) {
    string line;
    // Bỏ qua '\n' thừa còn sót từ lần nhập trước
    if (is.peek() == '\n') is.ignore();

    while (true) {
        cout << "  (Vi du: 1 2 la phan so 1/2, -3 4 la phan so -3/4)" << endl;
        cout << "  >> ";
        getline(is, line);

        istringstream iss(line);
        int t, m;
        char extra;

        if (!(iss >> t >> m)) {
            // Thiếu 1 hoặc cả 2 số, hoặc nhập chữ
            cout << "  Loi: Phai nhap dung 2 so nguyen cach nhau khoang trang!" << endl;
        } else if (iss >> extra) {
            // Nhập thừa ký tự sau 2 số
            cout << "  Loi: Chi nhap dung 2 so, khong them ky tu khac!" << endl;
        } else if (m == 0) {
            cout << "  Loi: Mau so khong duoc bang 0!" << endl;
        } else {
            f.tu = t;
            f.mau = m;
            f.simplify();
            break;
        }
        cout << "  Vui long nhap lai." << endl;
    }
    return is;
}
