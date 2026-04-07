/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTriangle.h"

using namespace std;

double cTriangle::perimeter() const {
    if (!isValid()) {
        return 0.0;
    }

    const vector<double> sides = sideLengths();
    return sides[0] + sides[1] + sides[2];
}