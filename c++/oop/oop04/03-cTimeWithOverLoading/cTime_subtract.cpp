/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// Tru di mot so nguyen giay
CTime CTime::operator-(int s) const {
    return CTime(gio, phut, giay - s); 
}