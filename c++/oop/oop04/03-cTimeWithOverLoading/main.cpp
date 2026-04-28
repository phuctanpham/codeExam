/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

int main() {
    cout << "========= TEST TREN THOI DIEM DON LE =========" << endl;
    CTime t1, t2;

    cout << "--- Nhap thoi diem 1 (t1) ---" << endl;
    cin >> t1;
    cout << "--- Nhap thoi diem 2 (t2) ---" << endl;
    cin >> t2;

    cout << "\n[+] t1 = " << t1 << endl;
    cout << "[+] t2 = " << t2 << endl;

    // Cong/Tru voi so giay nguyen
    cout << "\n========= CONG/TRU VOI SO GIAY =========" << endl;
    cout << "t1 + 90 giay  = " << (t1 + 90)  << endl;
    cout << "t1 - 90 giay  = " << (t1 - 90)  << endl;

    // [THEM MOI] Cong/Tru voi khoang thoi gian (CTime duration)
    cout << "\n========= CONG/TRU VOI KHOANG THOI GIAN (hh:mm:ss) =========" << endl;
    CTime duration;
    cout << "Nhap khoang thoi gian muon cong/tru (duration):" << endl;
    cin >> duration;
    cout << "t1 + " << duration << " = " << (t1 + duration) << endl;
    cout << "t1 - " << duration << " = " << (t1 - duration) << endl;

    // Tang/Giam 1 giay
    cout << "\n========= TANG/GIAM 1 GIAY (++/--) =========" << endl;
    CTime t3 = t1;
    cout << "t3 hien tai : " << t3 << endl;
    cout << "++t3 tra ve : " << ++t3 << " | t3 sau: " << t3 << endl;
    cout << "t3++ tra ve : " << t3++ << " | t3 sau: " << t3 << endl;
    cout << "--t3 tra ve : " << --t3 << " | t3 sau: " << t3 << endl;
    cout << "t3-- tra ve : " << t3-- << " | t3 sau: " << t3 << endl;

    // So sanh
    cout << "\n========= SO SANH =========" << endl;
    if (t1 == t2) cout << "t1 == t2" << endl;
    if (t1 != t2) cout << "t1 != t2" << endl;
    if (t1 >  t2) cout << "t1 xay ra SAU t2" << endl;
    if (t1 <  t2) cout << "t1 xay ra TRUOC t2" << endl;

    // [SUA] Chenh lech bieu dien dang hh:mm:ss thay vi so giay thuan tuy
    cout << "\n========= CHENH LECH THOI GIAN =========" << endl;
    CTime diff = t1.difference(t2);
    cout << "Chenh lech |t1 - t2| = " << diff << " (hh:mm:ss)" << endl;

    // [THEM MOI] Test tren day thoi diem
    cout << "\n========= TEST TREN DAY THOI DIEM =========" << endl;
    cTimes dayT;
    cin >> dayT;

    cout << "\nDay thoi diem da nhap:\n" << dayT << endl;
    cout << "Tong thoi luong : " << dayT.sum() << endl;
    cout << "Thoi diem lon nhat: " << dayT.max() << endl;
    cout << "Thoi diem nho nhat: " << dayT.min() << endl;

    dayT.sortAscending();
    cout << "\nSau khi sap xep tang dan:\n" << dayT << endl;

    return 0;
}
