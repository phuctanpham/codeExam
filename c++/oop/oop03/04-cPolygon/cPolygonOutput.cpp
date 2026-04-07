/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iomanip>
#include <iostream>

#include "cPolygon.h"

using namespace std;

void cPolygon::output() const {
    cout << fixed << setprecision(3);
    cout << "Da giac: " << polygonName << " (" << getSides() << " canh)\n";

    for (size_t i = 0; i < vertices.size(); ++i) {
        cout << "Diem " << (i + 1) << "(" << vertices[i].x << ", " << vertices[i].y << ")\n";
    }

    const vector<double> sides = sideLengths();
    for (size_t i = 0; i < sides.size(); ++i) {
        cout << "Do dai canh " << (i + 1) << " = " << sides[i] << "\n";
    }
    cout << "Loai da giac: " << polygonType() << "\n";
}
