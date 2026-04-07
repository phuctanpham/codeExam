/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTriangle.h"

using namespace std;

void cTriangle::translate(double dx, double dy) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        vertices[i].x += dx;
        vertices[i].y += dy;
    }
}