/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iomanip>
#include <iostream>

#include "cTriangle.h"

using namespace std;

void cTriangle::output() const {
    cout << fixed << setprecision(3);
    cout << "A(" << vertices[0].x << ", " << vertices[0].y << ")\n";
    cout << "B(" << vertices[1].x << ", " << vertices[1].y << ")\n";
    cout << "C(" << vertices[2].x << ", " << vertices[2].y << ")\n";

    const vector<double> sides = sideLengths();
    cout << "Do dai AB = " << sides[0] << "\n";
    cout << "Do dai BC = " << sides[1] << "\n";
    cout << "Do dai CA = " << sides[2] << "\n";
    cout << "Loai tam giac: " << triangleType() << "\n";
}