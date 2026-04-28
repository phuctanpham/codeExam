/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexNumber.h"

istream& operator>>(istream& is, cComplex& c) {
    string line;
    while (true) {
        if (!getline(is, line)) break;
        if (line.empty()) continue; // Bo qua dong trong do getline

        stringstream ss(line);
        float t, a;
        string extra;

        // Doc thanh cong 2 so thuc va khong con ky tu thua o phia sau
        if (ss >> t >> a) {
            if (!(ss >> extra)) {
                c.thuc = t;
                c.ao = a;
                break;
            }
        }
        cout << "Loi: Nhap sai dinh dang. Vui long nhap lai 2 so thuc (phan_thuc phan_ao): ";
    }
    return is;
}