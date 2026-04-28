/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

istream& operator>>(istream& is, cPolynomial& p) {
    string line;
    
    // Nhap bac da thuc (chan loi am, chu)
    while (true) {
        cout << "Nhap bac cua da thuc (n >= 0): ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int b;
        string extra;
        if (ss >> b && b >= 0 && !(ss >> extra)) {
            // Cap phat lai mang he so
            delete[] p.heSo;
            p.bac = b;
            p.heSo = new double[p.bac + 1];
            break;
        }
        cout << "Loi: Bac da thuc phai la so nguyen khong am. Vui long nhap lai.\n";
    }

    // Nhap tung he so tu bac cao nhat xuong bac 0
    for (int i = p.bac; i >= 0; --i) {
        while (true) {
            cout << "  -> Nhap he so cho x^" << i << ": ";
            if (!getline(is, line)) break;
            if (line.empty()) continue;

            stringstream ss(line);
            double val;
            string extra;
            if (ss >> val && !(ss >> extra)) {
                p.heSo[i] = val;
                break;
            }
            cout << "  [!] Loi: He so phai la so thuc. Vui long nhap lai.\n";
        }
    }
    return is;
}