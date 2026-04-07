/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

#include <iostream>

using namespace std;

void cArray::output() const {
    cout << "\n" << title << "\n";
    cout << "So phan tu: " << data.size() << "\n";
    cout << "Mang: ";

    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i];
        if (i + 1 < data.size()) {
            cout << ' ';
        }
    }

    cout << "\n";
}
