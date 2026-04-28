/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

ostream& operator<<(ostream& os, const cDate& d) {
    os << setfill('0') << setw(2) << d.ngay << "/"
       << setfill('0') << setw(2) << d.thang << "/"
       << setfill('0') << setw(4) << d.nam;
    return os;
}