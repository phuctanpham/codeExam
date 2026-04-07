/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <cmath>

#include "cPolygon.h"

using namespace std;

int cPolygon::instanceCount = 0;

cPolygon::cPolygon() : polygonName("DA GIAC") {
    vector<pair<double, double>> defaultPoints = {
        {0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}
    };
    setup(defaultPoints, "DA GIAC");
    ++instanceCount;
}

cPolygon::cPolygon(const vector<pair<double, double>>& points, const string& name)
    : polygonName(name) {
    setup(points, name);
    ++instanceCount;
}

cPolygon::~cPolygon() {
    if (instanceCount > 0) {
        --instanceCount;
    }
}

int cPolygon::getInstanceCount() {
    return instanceCount;
}

double cPolygon::distanceBetween(const Point& p1, const Point& p2) {
    const double dx = p1.x - p2.x;
    const double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

bool cPolygon::almostEqual(double a, double b) {
    return fabs(a - b) <= EPS;
}

double cPolygon::crossProduct(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<double> cPolygon::sideLengths() const {
    vector<double> sides;
    for (size_t i = 0; i < vertices.size(); ++i) {
        size_t next = (i + 1) % vertices.size();
        sides.push_back(distanceBetween(vertices[i], vertices[next]));
    }
    return sides;
}

bool cPolygon::setup(const vector<pair<double, double>>& points, const string& name) {
    if (points.size() < 3) {
        return false;
    }

    vertices.clear();
    for (const auto& p : points) {
        vertices.push_back({p.first, p.second});
    }
    polygonName = name;

    return isValid();
}
