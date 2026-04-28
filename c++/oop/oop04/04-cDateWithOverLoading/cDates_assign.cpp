/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDates.h"

// OVERLOADING toan tu = (Deep Copy & Chong tu gan)
cDates& cDates::operator=(const cDates& other) {
    if (this != &other) { 
        delete[] arr;
        n = other.n;
        arr = (n > 0) ? new cDate[n] : nullptr;
        for (int i = 0; i < n; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}