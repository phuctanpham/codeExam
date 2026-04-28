/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// Constructor mac dinh
cDates::cDates(int size) {
    n = size;
    arr = (n > 0) ? new cDate[n] : nullptr;
}

// Copy Constructor (Deep Copy de an toan bo nho)
cDates::cDates(const cDates& other) {
    n = other.n;
    arr = (n > 0) ? new cDate[n] : nullptr;
    for (int i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
}