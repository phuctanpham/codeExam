/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

istream& operator>>(istream& is, cPolynomials& ps) {
    string line;
    while (true) {
        cout << "Nhap so luong da thuc (n > 0): ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int size;
        string extra;
        if (ss >> size && size > 0 && !(ss >> extra)) {
            ps.n = size;
            break;
        }
        cout << "Loi: So luong phai la so nguyen duong. Vui long nhap lai.\n";
    }

    if (ps.arr != nullptr) delete[] ps.arr;
    ps.arr = new cPolynomial[ps.n];

    for (int i = 0; i < ps.n; ++i) {
        cout << "\n--- Nhap thong tin Da thuc thu " << i + 1 << " ---\n";
        is >> ps.arr[i]; // Tu dong goi >> cua cPolynomial
    }
    return is;
}