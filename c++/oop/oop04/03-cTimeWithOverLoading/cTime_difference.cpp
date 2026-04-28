/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [SUA] Doi ten tu operator-(CTime) thanh phuong thuc difference() rieng biet,
//        dong thoi doi kieu tra ve tu int (so giay thuan tuy) sang CTime
//        de bieu dien chenh lech dang hh:mm:ss ro rang hon.
// Vi du: difference(10:30:45, 08:15:20) => 02:15:25 thay vi 8125 giay
CTime CTime::difference(const CTime& other) const {
    int total1 = gio  * 3600 + phut  * 60 + giay;
    int total2 = other.gio * 3600 + other.phut * 60 + other.giay;
    int diff   = abs(total1 - total2); // Lay gia tri tuyet doi
    return CTime(0, 0, diff);          // Constructor + chuanHoa tu chuyen sang hh:mm:ss
}
