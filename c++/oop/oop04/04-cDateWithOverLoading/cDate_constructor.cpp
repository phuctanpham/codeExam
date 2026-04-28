/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

cDate::cDate(int d, int m, int y) {
    ngay = d;
    thang = m;
    nam = (y > 0) ? y : 1;
    chuanHoa(); // Goi ham chuan hoa de dam bao tinh hop le ngay tu khi tao
}