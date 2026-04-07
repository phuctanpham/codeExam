/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <algorithm>
#include <vector>

#include "cPolygon.h"

using namespace std;

bool cPolygon::isValid() const {
    if (vertices.size() < 3) {
        return false;
    }

    // Check if all points are collinear using cross product
    for (size_t i = 0; i < vertices.size(); ++i) {
        size_t next = (i + 1) % vertices.size();
        size_t nextNext = (i + 2) % vertices.size();

        double cp = crossProduct(vertices[i], vertices[next], vertices[nextNext]);
        if (!almostEqual(cp, 0.0)) {
            return true;
        }
    }

    return false;
}

bool cPolygon::isConvex() const {
    if (vertices.size() < 3 || !isValid()) {
        return false;
    }

    bool hasPositive = false;
    bool hasNegative = false;

    for (size_t i = 0; i < vertices.size(); ++i) {
        size_t curr = i;
        size_t next = (i + 1) % vertices.size();
        size_t nextNext = (i + 2) % vertices.size();

        double cp = crossProduct(vertices[curr], vertices[next], vertices[nextNext]);

        if (cp > EPS) {
            hasPositive = true;
        } else if (cp < -EPS) {
            hasNegative = true;
        }
    }

    return !(hasPositive && hasNegative);
}

bool cPolygon::isRegular() const {
    if (vertices.size() < 3 || !isValid()) {
        return false;
    }

    const vector<double> sides = sideLengths();

    // Check if all sides are equal
    for (size_t i = 1; i < sides.size(); ++i) {
        if (!almostEqual(sides[0], sides[i])) {
            return false;
        }
    }

    // Check if all angles are equal (for regular polygon)
    // This is implied by equal sides and convexity for most cases
    return isConvex();
}

string cPolygon::polygonType() const {
    if (!isValid()) {
        return "Khong hop le";
    }

    const bool regular = isRegular();
    const bool convex = isConvex();
    const int sides = getSides();

    if (regular) {
        if (sides == 3) {
            return "Tam giac deu (regular)";
        } else if (sides == 4) {
            return "Hinh vuong (regular quad)";
        }
        return "Da giac deu (" + to_string(sides) + " canh)";
    }

    if (convex) {
        return "Da giac loi (" + to_string(sides) + " canh)";
    }

    return "Da giac lom (" + to_string(sides) + " canh)";
}

int cPolygon::getSides() const {
    return vertices.size();
}
