/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"

// Tien to: tang roi tra ve
CTime& CTime::operator++() {
    giay++;
    chuanHoa();
    return *this;
}

// Hau to: luu ban sao, tang goc, tra ve ban sao
CTime CTime::operator++(int) {
    CTime temp = *this;
    giay++;
    chuanHoa();
    return temp;
}