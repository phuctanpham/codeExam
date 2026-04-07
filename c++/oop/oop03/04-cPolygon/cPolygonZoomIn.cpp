/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolygon.h"

using namespace std;

void cPolygon::zoomIn(double factor) {
    if (factor <= 0.0 || almostEqual(factor, 1.0)) {
        return;
    }

    double centerX = 0.0;
    double centerY = 0.0;

    for (size_t i = 0; i < vertices.size(); ++i) {
        centerX += vertices[i].x;
        centerY += vertices[i].y;
    }

    centerX /= static_cast<double>(vertices.size());
    centerY /= static_cast<double>(vertices.size());

    for (size_t i = 0; i < vertices.size(); ++i) {
        vertices[i].x = centerX + factor * (vertices[i].x - centerX);
        vertices[i].y = centerY + factor * (vertices[i].y - centerY);
    }
}
