/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

using namespace std;

int cArray::instanceCount = 0;

cArray::cArray() : title("MANG SO NGUYEN") {
    ++instanceCount;
}

cArray::cArray(const string& title) : title(title) {
    ++instanceCount;
}

int cArray::getInstanceCount() {
    return instanceCount;
}

size_t cArray::size() const {
    return data.size();
}

bool cArray::empty() const {
    return data.empty();
}
