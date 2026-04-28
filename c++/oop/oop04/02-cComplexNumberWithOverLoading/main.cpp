/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

int main() {
    cout << "========= TEST TREN SO PHUC DON LE =========" << endl;
    cComplex c1, c2;
    cout << "--- Nhap so phuc 1 ---" << endl;
    cin >> c1; 
    cout << "--- Nhap so phuc 2 ---" << endl;
    cin >> c2;

    cout << "\n[+] Tong: " << (c1 + c2) << endl;
    cout << "[-] Hieu: " << (c1 - c2) << endl;
    cout << "[*] Tich: " << (c1 * c2) << endl;
    cout << "[/] Thuong: " << (c1 / c2) << endl; 

    // Test chia cho 0
    cout << "\n[!] Test ngoai le chia cho so phuc 0:" << endl;
    cComplex cZero(0, 0);
    cComplex testDivZero = c1 / cZero;

    // Test Constructor tu so thuc
    cComplex cReal = 5.5; 
    cout << "\n[*] So thuc bien thanh so phuc: " << cReal << endl;

    if (c1 == c2) cout << "[=] Hai so phuc bang nhau." << endl;
    else if (c1 > c2) cout << "[>] So phuc 1 co Mo-dun lon hon so phuc 2." << endl;
    else cout << "[<] So phuc 1 co Mo-dun nho hon so phuc 2." << endl;

    cout << "\n========= TEST TREN DAY SO PHUC =========" << endl;
    cComplexes dayC;
    cin >> dayC;

    cout << "\nDay so phuc da nhap:\n" << dayC << endl;
    cout << "Tong cua day: " << dayC.sum() << endl;
    cout << "So phuc co Mo-dun lon nhat: " << dayC.max() << endl;
    cout << "So phuc co Mo-dun nho nhat: " << dayC.min() << endl;

    dayC.sortAscending();
    cout << "\nDay so phuc sau khi sap xep tang dan theo Mo-dun:\n" << dayC << endl;

    return 0;
}