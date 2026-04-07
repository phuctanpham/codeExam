/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_POLYGON_H
#define C_POLYGON_H

#include <string>
#include <vector>

using namespace std;

class cPolygon {
private:
    struct Point {
        double x;
        double y;
    };

    vector<Point> vertices;
    string polygonName;

    static int instanceCount;
    static constexpr double EPS = 1e-9;

    static double distanceBetween(const Point& p1, const Point& p2);
    static bool almostEqual(double a, double b);
    static double crossProduct(const Point& O, const Point& A, const Point& B);

public:
    cPolygon();
    cPolygon(const vector<pair<double, double>>& points, const string& name = "DA GIAC");
    ~cPolygon();

    static int getInstanceCount();

    bool setup(const vector<pair<double, double>>& points, const string& name = "DA GIAC");
    void input();
    void output() const;

    bool isValid() const;
    bool isConvex() const;
    bool isRegular() const;
    string polygonType() const;

    double perimeter() const;
    double area() const;
    int getSides() const;

    void translate(double dx, double dy);
    void zoomIn(double factor);
    void zoomOut(double factor);

    vector<double> sideLengths() const;
};

#endif
