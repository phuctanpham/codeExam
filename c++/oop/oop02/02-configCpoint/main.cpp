/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>

#include "cPoint.h"

using namespace std;

int main() {
    cPoint p1;
    cPoint p2;

    cout << "Nhập điểm p1\n";
    p1.input();

    cout << "\nNhập điểm p2\n";
    p2.input();

    cout << "\nCác điểm ban đầu:\n";
    cout << "p1 = ";
    p1.output();
    cout << "\np2 = ";
    p2.output();

    cout << "\n\nGán p1 bằng setValue(10.5, -2.5): ";
    p1.setValue(10.5, -2.5);
    p1.output();

    cout << "\nGán p2 bằng setX và setY: ";
    p2.setX(3.0);
    p2.setY(7.0);
    p2.output();

    cout << "\n\nLấy giá trị:\n";
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY() << "\n";
    cout << "p2.x = " << p2.getX() << ", p2.y = " << p2.getY() << "\n";

    cout << "\nTịnh tiến p1 với (2.0, -3.5): ";
    p1.translate(2.0, -3.5);
    p1.output();

    cout << "\nTịnh tiến p2 với (-1.0, 4.0): ";
    p2.translate(-1.0, 4.0);
    p2.output();

    cout << "\n";
    return 0;
}
