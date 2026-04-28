/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// Moc thoi gian som nhat (qua khu nhat)
cDate cDates::min() const {
    if (n == 0) return cDate();
    cDate minDate = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minDate) { // Goi toan tu < cua cDate
            minDate = arr[i];
        }
    }
    return minDate;
}