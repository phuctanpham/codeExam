/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <algorithm>
#include <vector>

#include "cTriangle.h"

using namespace std;

bool cTriangle::isValid() const {
    const double doubledArea =
        vertices[0].x * (vertices[1].y - vertices[2].y) +
        vertices[1].x * (vertices[2].y - vertices[0].y) +
        vertices[2].x * (vertices[0].y - vertices[1].y);

    return !almostEqual(doubledArea, 0.0);
}

bool cTriangle::isEquilateral() const {
    if (!isValid()) {
        return false;
    }

    const vector<double> sides = sideLengths();
    return almostEqual(sides[0], sides[1]) && almostEqual(sides[1], sides[2]);
}

bool cTriangle::isRegular() const {
    return isEquilateral();
}

bool cTriangle::isIsosceles() const {
    if (!isValid()) {
        return false;
    }

    const vector<double> sides = sideLengths();
    return almostEqual(sides[0], sides[1]) || almostEqual(sides[1], sides[2]) || almostEqual(sides[0], sides[2]);
}

bool cTriangle::isRight() const {
    if (!isValid()) {
        return false;
    }

    vector<double> sides = sideLengths();
    sort(sides.begin(), sides.end());

    const double left = sides[0] * sides[0] + sides[1] * sides[1];
    const double right = sides[2] * sides[2];
    return almostEqual(left, right);
}

string cTriangle::triangleType() const {
    if (!isValid()) {
        return "Khong hop le";
    }

    const bool equilateral = isEquilateral();
    const bool isosceles = isIsosceles();
    const bool right = isRight();

    if (equilateral) {
        return "Tam giac deu (regular)";
    }

    if (right && isosceles) {
        return "Tam giac vuong can";
    }

    if (right) {
        return "Tam giac vuong";
    }

    if (isosceles) {
        return "Tam giac can";
    }

    return "Tam giac thuong";
}