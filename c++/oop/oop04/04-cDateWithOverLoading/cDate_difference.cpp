/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// Ham ho tro cuc bo: Tinh tong so ngay tu thoi diem 01/01/0001
static int countLeapYears(int y, int m) {
    if (m <= 2) y--;
    return y / 4 - y / 100 + y / 400;
}

static int getAbsoluteDays(const cDate& d, int ng, int th, int nm) {
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int total = nm * 365 + ng;
    for (int i = 0; i < th - 1; i++) {
        total += monthDays[i];
    }
    total += countLeapYears(nm, th);
    return total;
}

// Toan tu tru 2 moc thoi gian (tra ve int - dung truc tiep de tinh lai suat)
int cDate::operator-(const cDate& other) const {
    int days1 = getAbsoluteDays(*this, ngay, thang, nam);
    int days2 = getAbsoluteDays(other, other.ngay, other.thang, other.nam);
    return days1 - days2; 
}