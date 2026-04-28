/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"

ostream& operator<<(ostream& os, const CTime& t) {
    // Dung thu vien iomanip de fill so 0 dang truoc neu < 10
    os << setfill('0') << setw(2) << t.gio << ":"
       << setfill('0') << setw(2) << t.phut << ":"
       << setfill('0') << setw(2) << t.giay;
    return os;
}