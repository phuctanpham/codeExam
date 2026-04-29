/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

int main() {
    cout << "=================================================\n";
    cout << "      PHAN 1: KIEM THU TREN 1 DA THUC DON LE    \n";
    cout << "=================================================\n";
    cPolynomial p1, p2;

    cout << ">> Nhap Da thuc P1(x):\n";
    cin >> p1;
    cout << ">> Nhap Da thuc P2(x):\n";
    cin >> p2;

    cout << "\n[+] P1(x) = " << p1 << endl;
    cout << "[+] P2(x) = " << p2 << endl;

    cout << "\n--- Cac phep toan tren P1 va P2 ---\n";
    cout << "P1 + P2 = " << (p1 + p2) << endl;
    cout << "P1 - P2 = " << (p1 - p2) << endl;
    cout << "P1 * P2 = " << (p1 * p2) << endl;

    // [SUA] Dung getline thay vi cin >> x de nhat quan voi cac phan nhap khac
    //        va tranh loi buffer khi ket hop cin >> voi getline o nhung lan sau.
    //        Them kiem tra hop le: x phai la so thuc.
    cout << "\nNhap gia tri x de tinh P1(x):\n";
    double x = 0.0;
    string line;
    while (true) {
        cout << "  (Vi du: 2.5 hoac -1)" << endl;
        cout << "  x = ";
        if (!getline(cin, line)) break;
        if (line.empty()) continue;
        stringstream ss(line);
        string extra;
        if (ss >> x && !(ss >> extra)) break;
        cout << "  Loi: x phai la so thuc. Vui long nhap lai." << endl;
    }
    cout << "P1(" << x << ") = " << p1.evaluate(x) << endl;

    cout << "\n--- So sanh P1 va P2 ---\n";
    if      (p1 == p2) cout << "P1 = P2 (Cung bac, cung he so)\n";
    else if (p1 >  p2) cout << "P1 > P2 (Uu tien so sanh bac roi den he so)\n";
    else               cout << "P1 < P2\n";

    cout << "\n=================================================\n";
    cout << "      PHAN 2: KIEM THU TREN DAY DA THUC         \n";
    cout << "=================================================\n";
    cPolynomials ds;
    cin >> ds;

    cout << "\n[+] Danh sach cac da thuc vua nhap:\n" << ds;
    cout << "\n[+] Da thuc lon nhat: " << ds.max() << endl;
    cout << "[+] Da thuc nho nhat: " << ds.min() << endl;

    ds.sortAscending();
    cout << "\n[+] Sau khi sap xep tang dan:\n" << ds;

    return 0;
}
