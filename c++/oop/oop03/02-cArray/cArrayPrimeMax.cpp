/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

#include <cmath>

using namespace std;

namespace {
bool isPrime(int value) {
    if (value < 2) {
        return false;
    }

    if (value == 2) {
        return true;
    }

    if (value % 2 == 0) {
        return false;
    }

    int limit = static_cast<int>(sqrt(static_cast<double>(value)));
    for (int i = 3; i <= limit; i += 2) {
        if (value % i == 0) {
            return false;
        }
    }

    return true;
}
}

int cArray::findPrimeMax() const {
    int maxPrime = -1;

    for (size_t i = 0; i < data.size(); ++i) {
        if (isPrime(data[i]) && data[i] > maxPrime) {
            maxPrime = data[i];
        }
    }

    return maxPrime;
}
