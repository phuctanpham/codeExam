/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

#include <algorithm>

using namespace std;

int cArray::countValue(int value) const {
    return static_cast<int>(count(data.begin(), data.end(), value));
}
