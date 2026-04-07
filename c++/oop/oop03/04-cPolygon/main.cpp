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

int main() {
    cout << "===== CHUONG TRINH MINH HOA LOP cPolygon =====\n\n";

    cPolygon polygon;
    polygon.input();

    cout << "\n===== cPolygonOutput.cpp =====\n";
    polygon.output();

    cout << fixed << setprecision(3);
    cout << "\n===== cPolygonCheck.cpp =====\n";
    cout << "Convex (loi): " << (polygon.isConvex() ? "Co" : "Khong") << "\n";
    cout << "Regular (deu): " << (polygon.isRegular() ? "Co" : "Khong") << "\n";
    cout << "So canh: " << polygon.getSides() << "\n";

    cout << "\n===== cPolygonPerimeter.cpp =====\n";
    cout << "Chu vi = " << polygon.perimeter() << "\n";

    cout << "\n===== cPolygonArea.cpp =====\n";
    cout << "Dien tich = " << polygon.area() << "\n";

    double dx = 0.0;
    double dy = 0.0;
    cout << "\n===== cPolygonTranslation.cpp =====\n";
    cout << "Nhap vector tinh tien (dx dy): ";
    cin >> dx >> dy;
    polygon.translate(dx, dy);
    cout << "Da giac sau tinh tien:\n";
    polygon.output();

    double zoomInFactor = 1.0;
    cout << "\n===== cPolygonZoomIn.cpp =====\n";
    cout << "Nhap he so phong to (>1): ";
    cin >> zoomInFactor;
    polygon.zoomIn(zoomInFactor);
    cout << "Da giac sau phong to:\n";
    polygon.output();

    double zoomOutFactor = 1.0;
    cout << "\n===== cPolygonZoomOut.cpp =====\n";
    cout << "Nhap he so thu nho (>1): ";
    cin >> zoomOutFactor;
    polygon.zoomOut(zoomOutFactor);
    cout << "Da giac sau thu nho:\n";
    polygon.output();

    return 0;
}
