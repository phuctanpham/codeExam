/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomial.h"

using namespace std;

double cPolynomial::maxValueWith(const cPolynomial& other, double x) const {
    const double thisValue = evaluate(x);
    const double otherValue = other.evaluate(x);
    return (thisValue > otherValue) ? thisValue : otherValue;
}
