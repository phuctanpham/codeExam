/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <cmath>

#include "cTriangle.h"

using namespace std;

double cTriangle::area() const {
    if (!isValid()) {
        return 0.0;
    }

    const vector<double> sides = sideLengths();
    const double halfPerimeter = perimeter() / 2.0;
    const double squareArea =
        halfPerimeter * (halfPerimeter - sides[0]) * (halfPerimeter - sides[1]) * (halfPerimeter - sides[2]);

    if (squareArea <= EPS) {
        return 0.0;
    }

    return sqrt(squareArea);
}