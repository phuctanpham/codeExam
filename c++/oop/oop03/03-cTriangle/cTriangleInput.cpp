/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>
#include <limits>

#include "cTriangle.h"

using namespace std;

void cTriangle::input() {
    double ax = 0.0;
    double ay = 0.0;
    double bx = 0.0;
    double by = 0.0;
    double cx = 0.0;
    double cy = 0.0;

    auto readPoint = [](const string& label, Point& p) {
        while (true) {
            cout << label << flush;
            if (cin >> p.x >> p.y) {
                return true;
            }

            if (cin.eof()) {
                return false;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Du lieu khong hop le. Vui long nhap 2 so thuc theo dang: x y\n";
        }
    };

    triangleName = "TAM GIAC";

    while (true) {
        Point pa;
        Point pb;
        Point pc;

        if (!readPoint("Nhap toa do A(x, y): ", pa)) {
            return;
        }
        if (!readPoint("Nhap toa do B(x, y): ", pb)) {
            return;
        }
        if (!readPoint("Nhap toa do C(x, y): ", pc)) {
            return;
        }

        ax = pa.x;
        ay = pa.y;
        bx = pb.x;
        by = pb.y;
        cx = pc.x;
        cy = pc.y;

        if (setup(ax, ay, bx, by, cx, cy, "TAM GIAC")) {
            break;
        }

        cout << "Ba diem dang thang hang. Vui long nhap lai toa do 3 dinh.\n";
    }

}