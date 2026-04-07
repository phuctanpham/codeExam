/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolygon.h"

using namespace std;

void cPolygon::zoomOut(double factor) {
    if (factor <= 0.0 || almostEqual(factor, 1.0)) {
        return;
    }

    zoomIn(1.0 / factor);
}
