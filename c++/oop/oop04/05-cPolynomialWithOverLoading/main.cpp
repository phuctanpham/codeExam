/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

int main() {
    cout << "=================================================\n";
    cout << "      PHAN 1: KIEM THU TREN 1 DA THUC DON LE     \n";
    cout << "=================================================\n";
    cPolynomial p1, p2;
    
    cout << ">> Nhap Da thuc P1(x):\n";
    cin >> p1;
    cout << ">> Nhap Da thuc P2(x):\n";
    cin >> p2;

    cout << "\n[+] P1(x) = " << p1 << endl;
    cout << "[+] P2(x) = " << p2 << endl;

    // Test cac phep toan toan hoc
    cout << "\n--- Cac phep toan tren P1 va P2 ---\n";
    cout << "P1(x) + P2(x) = " << (p1 + p2) << endl;
    cout << "P1(x) - P2(x) = " << (p1 - p2) << endl;
    cout << "P1(x) * P2(x) = " << (p1 * p2) << endl;

    // Test tinh gia tri (Horner)
    double x;
    cout << "\nNhap gia tri x de tinh P1(x): ";
    cin >> x;
    cin.ignore(256, '\n'); // Don sach bo dem
    cout << "Gia tri cua P1(" << x << ") = " << p1.evaluate(x) << endl;

    // Test toan tu so sanh
    cout << "\n--- So sanh P1 va P2 ---\n";
    if (p1 == p2) cout << "P1 bang P2 (Cung bac, cung he so)\n";
    else if (p1 > p2) cout << "P1 lon hon P2 (Uu tien so sanh bac roi toi he so)\n";
    else cout << "P1 nho hon P2\n";


    cout << "\n=================================================\n";
    cout << "      PHAN 2: KIEM THU TREN DAY DA THUC          \n";
    cout << "=================================================\n";
    cPolynomials ds;
    cin >> ds;

    cout << "\n[+] Danh sach cac da thuc vua nhap:\n";
    cout << ds;

    cout << "\n[+] Da thuc lon nhat: " << ds.max() << endl;
    cout << "[+] Da thuc nho nhat: " << ds.min() << endl;

    ds.sortAscending();
    cout << "\n[+] Danh sach sau khi sap xep tang dan:\n";
    cout << ds;

    return 0;
}