/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"
#include "cAccount.h"
#include <cmath>

int main() {
    // =============================================
    // PHAN 1: KIEM THU LOP CDATE DON LE
    // [SUA] Bo sung phan test rieng cho cDate don le de kiem tra day du
    //        cac toan tu overloading: +, -, ++, --, so sanh, getWeekday
    // =============================================
    cout << "=============================================\n";
    cout << "   PHAN 1: KIEM THU LOP CDATE DON LE        \n";
    cout << "=============================================\n";

    cDate d1, d2;
    cout << "--- Nhap ngay 1 (d1) ---\n";
    cin >> d1;
    cout << "--- Nhap ngay 2 (d2) ---\n";
    cin >> d2;

    cout << "\n[+] d1 = " << d1 << " (" << d1.getWeekday() << ")" << endl;
    cout << "[+] d2 = " << d2 << " (" << d2.getWeekday() << ")" << endl;

    cout << "\n--- Cong/Tru voi so nguyen ngay ---\n";
    cout << "d1 + 30 ngay = " << (d1 + 30) << endl;
    cout << "d1 - 30 ngay = " << (d1 - 30) << endl;

    cout << "\n--- Tang/Giam 1 ngay (++/--) ---\n";
    cDate d3 = d1;
    cout << "d3 hien tai : " << d3 << endl;
    cout << "++d3 tra ve : " << ++d3 << " | d3 sau: " << d3 << endl;
    cout << "d3++ tra ve : " << d3++ << " | d3 sau: " << d3 << endl;
    cout << "--d3 tra ve : " << --d3 << " | d3 sau: " << d3 << endl;
    cout << "d3-- tra ve : " << d3-- << " | d3 sau: " << d3 << endl;

    cout << "\n--- So sanh ---\n";
    if (d1 == d2) cout << "d1 == d2\n";
    if (d1 != d2) cout << "d1 != d2\n";
    if (d1 >  d2) cout << "d1 xay ra SAU d2\n";
    if (d1 <  d2) cout << "d1 xay ra TRUOC d2\n";

    cout << "\n--- Chenh lech ---\n";
    int diff = d1 - d2;
    cout << "d1 - d2 = " << diff << " ngay (co dau)\n";
    cout << "|d1 - d2| = " << abs(diff) << " ngay\n";

    // =============================================
    // PHAN 2: KIEM THU DAY CDATES
    // =============================================
    cout << "\n=============================================\n";
    cout << "   PHAN 2: KIEM THU DAY CDATES               \n";
    cout << "=============================================\n";

    cDates ds;
    cin >> ds;

    cout << "\n[+] Danh sach cac moc thoi gian:\n" << ds << endl;
    cout << "\n[+] Moc thoi gian som nhat (Min): " << ds.min() << endl;
    cout << "[+] Moc thoi gian tre nhat (Max): " << ds.max() << endl;

    ds.sortAscending();
    cout << "\n[+] Danh sach sau khi sap xep tang dan:\n" << ds << endl;

    // =============================================
    // PHAN 3: UNG DUNG TINH LAI SUAT NGAN HANG
    // =============================================
    cout << "\n=============================================\n";
    cout << "   PHAN 3: UNG DUNG TINH LAI SUAT NGAN HANG \n";
    cout << "=============================================\n";

    cAccount myAcc;
    cin >> myAcc;

    cout << "\n=== KET QUA TINH TOAN ===\n";
    cout << myAcc;

    return 0;
}
