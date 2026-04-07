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

int main() {
    cout << "===== CHUONG TRINH MINH HOA LOP cTriangle =====\n\n";

    cTriangle t1;
    t1.input();

    cout << "\n===== cTriangleOutput.cpp =====\n";
    t1.output();

    cout << fixed << setprecision(3);
    cout << "\n===== cTriangleCheck.cpp =====\n";
    cout << "Regular (deu): " << (t1.isRegular() ? "Co" : "Khong") << "\n";
    cout << "Right (vuong): " << (t1.isRight() ? "Co" : "Khong") << "\n";
    cout << "Isosceles (can): " << (t1.isIsosceles() ? "Co" : "Khong") << "\n";
    cout << "Equilateral (deu): " << (t1.isEquilateral() ? "Co" : "Khong") << "\n";

    cout << "\n===== cTrianglePerimeter.cpp =====\n";
    cout << "Chu vi = " << t1.perimeter() << "\n";

    cout << "\n===== cTriangleArea.cpp =====\n";
    cout << "Dien tich = " << t1.area() << "\n";

    double dx = 0.0;
    double dy = 0.0;
    cout << "\n===== cTriangleTranslation.cpp =====\n";
    cout << "Nhap vector tinh tien (dx dy): ";
    cin >> dx >> dy;
    t1.translate(dx, dy);
    cout << "Tam giac sau tinh tien:\n";
    t1.output();

    double zoomInFactor = 1.0;
    cout << "\n===== cTriangleZoomIn.cpp =====\n";
    cout << "Nhap he so phong to (>1): ";
    cin >> zoomInFactor;
    t1.zoomIn(zoomInFactor);
    cout << "Tam giac sau phong to:\n";
    t1.output();

    double zoomOutFactor = 1.0;
    cout << "\n===== cTriangleZoomOut.cpp =====\n";
    cout << "Nhap he so thu nho (>1): ";
    cin >> zoomOutFactor;
    t1.zoomOut(zoomOutFactor);
    cout << "Tam giac sau thu nho:\n";
    t1.output();

    return 0;
}