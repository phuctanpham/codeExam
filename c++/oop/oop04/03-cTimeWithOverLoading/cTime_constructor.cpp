/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"

CTime::CTime(int h, int m, int s) {
    gio = h;
    phut = m;
    giay = s;
    chuanHoa(); // Goi chuan hoa de dam bao gia tri luon hop le ngay tu khi khoi tao
}