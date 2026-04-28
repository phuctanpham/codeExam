/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

bool cDate::isLeapYear() const {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

int cDate::daysInMonth() const {
    switch (thang) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear() ? 29 : 28;
        default:
            return 31;
    }
}

// Chuan hoa moc thoi gian (xu ly viec cong/tru bi tran ngay)
void cDate::chuanHoa() {
    while (thang > 12) {
        nam++;
        thang -= 12;
    }
    while (thang <= 0) {
        nam--;
        thang += 12;
    }
    while (ngay > daysInMonth()) {
        ngay -= daysInMonth();
        thang++;
        if (thang > 12) {
            nam++;
            thang -= 12;
        }
    }
    while (ngay <= 0) {
        thang--;
        if (thang <= 0) {
            nam--;
            thang += 12;
        }
        ngay += daysInMonth();
    }
    if (nam <= 0) nam = 1; // Mac dinh chan duoi nam
}