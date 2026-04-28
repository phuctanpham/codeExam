/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"

bool CTime::operator==(const CTime& other) const {
    return (gio == other.gio && phut == other.phut && giay == other.giay);
}

bool CTime::operator!=(const CTime& other) const {
    return !(*this == other);
}

bool CTime::operator>(const CTime& other) const {
    int total1 = gio * 3600 + phut * 60 + giay;
    int total2 = other.gio * 3600 + other.phut * 60 + other.giay;
    return total1 > total2;
}

bool CTime::operator<(const CTime& other) const {
    int total1 = gio * 3600 + phut * 60 + giay;
    int total2 = other.gio * 3600 + other.phut * 60 + other.giay;
    return total1 < total2;
}