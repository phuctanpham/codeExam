/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

int main() {
    // 1. Test các toán tử OVERLOADING trên 1 phân số đơn lẻ
    cout << "--- TEST TREN PHAN SO DON LE ---" << endl;
    cFraction ps1, ps2;
    cout << "Nhap phan so 1 (tu mau): "; 
    cin >> ps1; // Gọi OVERLOADING >>
    
    cout << "Nhap phan so 2 (tu mau): "; 
    cin >> ps2; // Gọi OVERLOADING >>

    cout << "Phep Cong (+): " << (ps1 + ps2) << endl; // Gọi OVERLOADING + và <<
    cout << "Phep Tru (-): " << (ps1 - ps2) << endl;
    cout << "Phep Nhan (*): " << (ps1 * ps2) << endl;
    cout << "Phep Chia (/): " << (ps1 / ps2) << endl;

    if (ps1 == ps2) cout << "ps1 va ps2 bang nhau." << endl;
    else if (ps1 > ps2) cout << "ps1 lon hon ps2." << endl;
    else cout << "ps1 nho hon ps2." << endl;

    // Test OVERLOADING khởi tạo từ 1 số nguyên
    cFraction ps3 = 5; 
    cout << "Phan so dac biet tu so nguyen 5: " << ps3 << endl;

    // 2. Test trên dãy phân số
    cout << "\n--- TEST TREN DAY PHAN SO ---" << endl;
    cFractions dayPS;
    cin >> dayPS; // Gọi OVERLOADING >> cho mảng

    cout << "Danh sach phan so: " << dayPS << endl; // Gọi OVERLOADING << cho mảng
    cout << "Tong cac phan so: " << dayPS.sum() << endl;
    cout << "Phan so lon nhat: " << dayPS.max() << endl;
    cout << "Phan so nho nhat: " << dayPS.min() << endl;

    dayPS.sortAscending();
    cout << "Danh sach sau khi sap xep tang dan: " << dayPS << endl;

    return 0;
}