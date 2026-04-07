/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

using namespace std;

bool cArray::isAscending() const {
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }

    return true;
}
