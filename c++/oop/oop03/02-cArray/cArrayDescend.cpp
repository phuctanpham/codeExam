/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

using namespace std;

void cArray::sortDescending() {
    for (size_t i = 1; i < data.size(); ++i) {
        int key = data[i];
        int j = static_cast<int>(i) - 1;

        while (j >= 0 && data[j] < key) {
            data[j + 1] = data[j];
            --j;
        }

        data[j + 1] = key;
    }
}
