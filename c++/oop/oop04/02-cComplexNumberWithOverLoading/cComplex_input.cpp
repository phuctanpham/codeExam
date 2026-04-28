/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

// [SỬA] Thêm hướng dẫn và ví dụ ngay từ lần nhập đầu tiên (không chỉ khi nhập sai),
//        giúp người dùng biết định dạng mà không cần thử sai trước.
istream& operator>>(istream& is, cComplex& c) {
    string line;
    while (true) {
        cout << "  (Vi du: 1.5 -2 la so phuc 1.5 - 2i, 0 3 la so phuc 3i)" << endl;
        cout << "  >> ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        float t, a;
        string extra;

        if (ss >> t >> a && !(ss >> extra)) {
            c.thuc = t;
            c.ao   = a;
            break;
        }
        cout << "  Loi: Phai nhap dung 2 so thuc cach nhau khoang trang. Vui long nhap lai." << endl;
    }
    return is;
}
