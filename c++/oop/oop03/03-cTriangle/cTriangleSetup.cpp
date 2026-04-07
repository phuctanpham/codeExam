/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <cmath>

#include "cTriangle.h"

using namespace std;

int cTriangle::instanceCount = 0;

cTriangle::cTriangle() : vertices(3), triangleName("TAM GIAC") {
    setup(0.0, 0.0, 1.0, 0.0, 0.0, 1.0, "TAM GIAC");
    ++instanceCount;
}

cTriangle::cTriangle(double ax, double ay, double bx, double by, double cx, double cy, const string& name)
    : vertices(3), triangleName(name) {
    setup(ax, ay, bx, by, cx, cy, name);
    ++instanceCount;
}

cTriangle::~cTriangle() {
    if (instanceCount > 0) {
        --instanceCount;
    }
}

int cTriangle::getInstanceCount() {
    return instanceCount;
}

double cTriangle::distanceBetween(const Point& p1, const Point& p2) {
    const double dx = p1.x - p2.x;
    const double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

bool cTriangle::almostEqual(double a, double b) {
    return fabs(a - b) <= EPS;
}

vector<double> cTriangle::sideLengths() const {
    return {
        distanceBetween(vertices[0], vertices[1]),
        distanceBetween(vertices[1], vertices[2]),
        distanceBetween(vertices[2], vertices[0])
    };
}

bool cTriangle::setup(double ax, double ay, double bx, double by, double cx, double cy, const string& name) {
    vertices[0] = {ax, ay};
    vertices[1] = {bx, by};
    vertices[2] = {cx, cy};
    triangleName = name;

    return isValid();
}