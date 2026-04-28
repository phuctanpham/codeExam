/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"
#include "cAccount.h"

int main() {
    cout << "=============================================\n";
    cout << "   PHAN 1: KIEM THU LOP CDATE & DAY CDATES   \n";
    cout << "=============================================\n";
    
    cDates ds;
    cin >> ds;
    cout << "\n[+] Danh sach cac moc thoi gian:\n" << ds << endl;
    cout << "\n[+] Moc thoi gian som nhat (Min): " << ds.min() << endl;
    cout << "[+] Moc thoi gian tre nhat (Max): " << ds.max() << endl;
    
    ds.sortAscending();
    cout << "\n[+] Danh sach sau khi sap xep tang dan:\n" << ds << endl;

    cout << "\n=============================================\n";
    cout << "   PHAN 2: UNG DUNG TINH LAI SUAT NGAN HANG  \n";
    cout << "=============================================\n";
    
    cAccount myAcc;
    cin >> myAcc;
    
    cout << "\n=== KET QUA TINH TOAN ===\n";
    cout << myAcc;

    return 0;
}