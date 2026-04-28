/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"
#include <cmath>

// Tinh khoang cach (so giay) giua 2 thoi diem (tra ve gia tri co dau)
int CTime::operator-(const CTime& other) const {
    int total1 = gio * 3600 + phut * 60 + giay;
    int total2 = other.gio * 3600 + other.phut * 60 + other.giay;
    
    // De biet chinh xac thoi gian 1 cach thoi gian 2 bao nhieu giay. 
    // Nguoi dung co the tu abs() tren main neu chi quan tam den do lon.
    return total1 - total2;
}