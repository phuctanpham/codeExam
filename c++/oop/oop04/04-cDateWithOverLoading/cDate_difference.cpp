/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// Ham ho tro: tinh so nam nhuan tu nam 1 den nam y (tinh den thang m)
static int countLeapYears(int y, int m) {
    if (m <= 2) y--;
    return y / 4 - y / 100 + y / 400;
}

// [SUA] Xoa tham so "const cDate& d" thua khong duoc su dung trong ham goc,
//        giu lai 3 tham so thuc su can thiet: ng, th, nm
static int getAbsoluteDays(int ng, int th, int nm) {
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = nm * 365 + ng;
    for (int i = 0; i < th - 1; i++)
        total += monthDays[i];
    total += countLeapYears(nm, th);
    return total;
}

// Toan tu tru 2 moc thoi gian -> tra ve so nguyen ngay chenh lech (co dau)
int cDate::operator-(const cDate& other) const {
    int days1 = getAbsoluteDays(ngay, thang, nam);
    int days2 = getAbsoluteDays(other.ngay, other.thang, other.nam);
    return days1 - days2;
}
