/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"
#include <cmath> // Dung cho ham abs()

int main() {
    cout << "========= CHUONG TRINH TEST LOP CTIME =========" << endl;
    CTime t1, t2;

    // 1. Test chuc nang Nhap (co chong nhap sai)
    cout << "--- Nhap thoi gian 1 (t1) ---" << endl;
    cout << "Vui long nhap (hh mm ss): ";
    cin >> t1;

    cout << "\n--- Nhap thoi gian 2 (t2) ---" << endl;
    cout << "Vui long nhap (hh mm ss): ";
    cin >> t2;

    // 2. Test chuc nang Xuat (dinh dang hh:mm:ss)
    cout << "\n[+] Thoi gian 1 vua nhap: " << t1 << endl;
    cout << "[+] Thoi gian 2 vua nhap: " << t2 << endl;

    // 3. Test phep Cong/Tru voi mot so nguyen giay
    cout << "\n========= TEST CONG/TRU VOI SO NGUYEN GIAY =========" << endl;
    int s;
    cout << "Nhap so giay (n) muon cong/tru vao t1: ";
    cin >> s; // De don gian trong file test nay, gia dinh n nhap dung chuan la so nguyen
    cout << "t1 + " << s << " giay = " << (t1 + s) << endl;
    cout << "t1 - " << s << " giay = " << (t1 - s) << endl;

    // 4. Test phep Tang/Giam 1 giay (Tien to va Hau to)
    cout << "\n========= TEST TANG/GIAM 1 GIAY (++/--) =========" << endl;
    CTime t3 = t1; // Khoi tao t3 giong t1 de test doc lap
    cout << "[*] Thoi gian hien tai (t3): " << t3 << endl;
    
    cout << "- Tien to (++t3) tra ve: " << ++t3 << " | Sau khi goi: " << t3 << endl;
    cout << "- Hau to (t3++)  tra ve: " << t3++ << " | Sau khi goi: " << t3 << endl;
    
    cout << "- Tien to (--t3) tra ve: " << --t3 << " | Sau khi goi: " << t3 << endl;
    cout << "- Hau to (t3--)  tra ve: " << t3-- << " | Sau khi goi: " << t3 << endl;

    // 5. Test cac toan tu So sanh
    cout << "\n========= TEST TOAN TU SO SANH =========" << endl;
    if (t1 == t2) cout << "[=] t1 va t2 la cung mot thoi diem." << endl;
    if (t1 != t2) cout << "[!=] t1 va t2 khac thoi diem." << endl;
    if (t1 > t2) cout << "[>] t1 xay ra SAU t2." << endl;
    if (t1 < t2) cout << "[<] t1 xay ra TRUOC t2." << endl;

    // 6. Test khoang cach thoi gian giua 2 thoi diem
    cout << "\n========= TEST KHOANG CACH THOI GIAN =========" << endl;
    int diff = t1 - t2;
    cout << "Khoang cach t1 - t2 (tinh bang giay): " << diff << endl;
    cout << "Do lech tuyet doi giua t1 va t2: " << abs(diff) << " giay." << endl;

    cout << "\n===============================================" << endl;
    return 0;
}