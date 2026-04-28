/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

cDate cDate::operator-(int days) const {
    cDate res = *this;
    res.ngay -= days;
    res.chuanHoa();
    return res;
}