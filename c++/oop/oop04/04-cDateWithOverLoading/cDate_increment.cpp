/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// Tien to
cDate& cDate::operator++() {
    ngay++;
    chuanHoa();
    return *this;
}

// Hau to
cDate cDate::operator++(int) {
    cDate temp = *this;
    ngay++;
    chuanHoa();
    return temp;
}