/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

bool cDate::operator==(const cDate& other) const {
    return (nam == other.nam && thang == other.thang && ngay == other.ngay);
}

bool cDate::operator!=(const cDate& other) const {
    return !(*this == other);
}

bool cDate::operator>(const cDate& other) const {
    if (nam != other.nam) return nam > other.nam;
    if (thang != other.thang) return thang > other.thang;
    return ngay > other.ngay;
}

bool cDate::operator<(const cDate& other) const {
    if (nam != other.nam) return nam < other.nam;
    if (thang != other.thang) return thang < other.thang;
    return ngay < other.ngay;
}