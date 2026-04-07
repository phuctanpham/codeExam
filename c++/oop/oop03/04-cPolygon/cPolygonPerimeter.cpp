/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolygon.h"

using namespace std;

double cPolygon::perimeter() const {
    if (!isValid()) {
        return 0.0;
    }

    const vector<double> sides = sideLengths();
    double sum = 0.0;
    for (const double side : sides) {
        sum += side;
    }
    return sum;
}
