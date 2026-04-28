/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// Tinh thu bang thuat toan Zeller hoac cong thuc modulo don gian 
string cDate::getWeekday() const {
    int d = ngay;
    int m = thang;
    int y = nam;
    
    // Thang 1, 2 duoc xem la thang 13, 14 cua nam truoc
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    
    int K = y % 100;
    int J = y / 100;
    
    int h = (d + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    
    // h = 0 (Thu 7), 1 (Chu Nhat), 2 (Thu 2), ...
    switch (h) {
        case 0: return "Thu 7";
        case 1: return "Chu Nhat";
        case 2: return "Thu 2";
        case 3: return "Thu 3";
        case 4: return "Thu 4";
        case 5: return "Thu 5";
        case 6: return "Thu 6";
        default: return "Khong xac dinh";
    }
}