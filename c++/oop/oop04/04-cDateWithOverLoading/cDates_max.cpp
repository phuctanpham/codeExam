/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// Moc thoi gian tre nhat (tuong lai nhat)
cDate cDates::max() const {
    if (n == 0) return cDate();
    cDate maxDate = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxDate) { // Goi toan tu > cua cDate
            maxDate = arr[i];
        }
    }
    return maxDate;
}