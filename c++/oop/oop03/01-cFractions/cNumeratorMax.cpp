/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

using namespace std;

namespace {
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; static_cast<long long>(i) * i <= number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

bool isLessFraction(const cFraction& left, const cFraction& right) {
    return static_cast<long long>(left.getNumerator()) * right.getDenominator()
         < static_cast<long long>(right.getNumerator()) * left.getDenominator();
}
}

cFraction cFractions::findLargestPrimeNumerator() const {
    cFraction best;
    bool foundPrimeNumerator = false;

    for (const cFraction& fraction : fractions) {
        const int numerator = fraction.getNumerator();

        if (!isPrime(numerator)) {
            continue;
        }

        if (!foundPrimeNumerator
            || numerator > best.getNumerator()
            || (numerator == best.getNumerator() && isLessFraction(best, fraction))) {
            best = fraction;
            foundPrimeNumerator = true;
        }
    }

    return best;
}