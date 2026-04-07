/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

#include <algorithm>

using namespace std;

int cArray::findFractionMin() const {
    if (data.empty()) {
        return 0;
    }

    return *min_element(data.begin(), data.end());
}
