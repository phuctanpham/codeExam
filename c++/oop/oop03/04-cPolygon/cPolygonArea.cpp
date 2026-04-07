/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <cmath>

#include "cPolygon.h"

using namespace std;

double cPolygon::area() const {
    if (!isValid()) {
        return 0.0;
    }

    // Using shoelace formula
    double sum = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        size_t next = (i + 1) % vertices.size();
        sum += vertices[i].x * vertices[next].y - vertices[next].x * vertices[i].y;
    }

    return fabs(sum) / 2.0;
}
