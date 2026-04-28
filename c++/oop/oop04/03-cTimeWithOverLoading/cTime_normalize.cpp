/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// Xu ly tinh toan tran so hoac bi am (khi tru thoi gian)
void CTime::chuanHoa() {
    // Xu ly giay
    if (giay < 0) {
        int vay = (-giay) / 60 + 1;
        if ((-giay) % 60 == 0) vay--;
        phut -= vay;
        giay += vay * 60;
    }
    phut += giay / 60;
    giay %= 60;

    // Xu ly phut
    if (phut < 0) {
        int vay = (-phut) / 60 + 1;
        if ((-phut) % 60 == 0) vay--;
        gio -= vay;
        phut += vay * 60;
    }
    gio += phut / 60;
    phut %= 60;

    // Xu ly gio (Quay vong 24h)
    gio %= 24;
    if (gio < 0) gio += 24;
}