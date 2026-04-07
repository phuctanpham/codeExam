/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_TRIANGLE_H
#define C_TRIANGLE_H

#include <string>
#include <vector>

using namespace std;

class cTriangle {
private:
    struct Point {
        double x;
        double y;
    };

    vector<Point> vertices;
    string triangleName;

    static int instanceCount;
    static constexpr double EPS = 1e-9;

    static double distanceBetween(const Point& p1, const Point& p2);
    static bool almostEqual(double a, double b);

public:
    cTriangle();
    cTriangle(double ax, double ay, double bx, double by, double cx, double cy, const string& name = "TAM GIAC");
    ~cTriangle();

    static int getInstanceCount();

    bool setup(double ax, double ay, double bx, double by, double cx, double cy, const string& name = "TAM GIAC");
    void input();
    void output() const;

    bool isValid() const;
    bool isRegular() const;
    bool isRight() const;
    bool isIsosceles() const;
    bool isEquilateral() const;
    string triangleType() const;

    double perimeter() const;
    double area() const;

    void translate(double dx, double dy);
    void zoomIn(double factor);
    void zoomOut(double factor);

    vector<double> sideLengths() const;
};

#endif