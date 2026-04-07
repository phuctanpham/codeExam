/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolygon.h"

using namespace std;

void cPolygon::translate(double dx, double dy) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        vertices[i].x += dx;
        vertices[i].y += dy;
    }
}
