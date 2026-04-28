/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexes.h"

void cComplexes::sortAscending() {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) { 
                cComplex temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}