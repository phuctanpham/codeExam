/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_POINT_H
#define C_POINT_H

#include <iostream>

class cPoint {
private:
    double x;
    double y;

public:
    cPoint();
    cPoint(double x, double y);
    cPoint(const cPoint& other);

    void setValue(double newX, double newY);
    void setX(double newX);
    void setY(double newY);

    double getX() const;
    double getY() const;

    void translate(double dx, double dy);

    void input();
    void output() const;
};

#endif
