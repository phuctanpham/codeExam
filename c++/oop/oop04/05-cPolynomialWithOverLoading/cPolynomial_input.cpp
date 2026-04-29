/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

istream& operator>>(istream& is, cPolynomial& p) {
    string line;

    // Nhap bac da thuc
    // [SUA] Hien thi huong dan va vi du ngay tu lan nhap dau tien (nhu cac bai truoc)
    while (true) {
        cout << "  (Bac da thuc phai la so nguyen >= 0, vi du: 2 la da thuc bac 2)" << endl;
        cout << "  Bac (n): ";
        if (!getline(is, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        int b;
        string extra;
        if (ss >> b && b >= 0 && !(ss >> extra)) {
            delete[] p.heSo;
            p.bac = b;
            // [SUA] Khoi tao mang he so ve 0 sau khi cap phat
            // Truoc day de un-initialized → rac bo nho neu EOF xay ra giua chung
            p.heSo = new double[p.bac + 1]();  // () = zero-initialize
            break;
        }
        cout << "  Loi: Bac phai la so nguyen khong am. Vui long nhap lai." << endl;
    }

    // Nhap tung he so tu bac cao xuong bac 0
    for (int i = p.bac; i >= 0; --i) {
        while (true) {
            cout << "  (He so la so thuc, vi du: -3.5 hoac 2)" << endl;
            cout << "  He so x^" << i << ": ";
            if (!getline(is, line)) break;
            if (line.empty()) continue;

            stringstream ss(line);
            double val;
            string extra;
            if (ss >> val && !(ss >> extra)) {
                p.heSo[i] = val;
                break;
            }
            cout << "  Loi: He so phai la so thuc. Vui long nhap lai." << endl;
        }
    }

    // [SUA] Goi normalize() sau khi nhap xong de chuan hoa bac
    // Tranh truong hop nguoi dung nhap bac=2 nhung he so bac 2 = 0
    // Vi du: bac=2, heSo=[1, 0, 0] → thuc chat la hang so 1 (bac=0)
    p.normalize();
    return is;
}
