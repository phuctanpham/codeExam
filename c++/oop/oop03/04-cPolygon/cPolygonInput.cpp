/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>
#include <limits>

#include "cPolygon.h"

using namespace std;

void cPolygon::input() {
    int n = 0;

    while (true) {
        cout << "Nhap so canh cua da giac (n >= 3): " << flush;
        if (cin >> n && n >= 3) {
            break;
        }

        if (cin.eof()) {
            return;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "So canh phai >= 3. Vui long nhap lai.\n";
    }

    polygonName = "DA GIAC";

    auto readPoint = [](const string& label, double& x, double& y) {
        while (true) {
            cout << label << flush;
            if (cin >> x >> y) {
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

    while (true) {
        vector<pair<double, double>> points;

        for (int i = 0; i < n; ++i) {
            double x = 0.0;
            double y = 0.0;
            string label = "Nhap toa do diem " + to_string(i + 1) + "(x, y): ";
            if (!readPoint(label, x, y)) {
                return;
            }
            points.push_back({x, y});
        }

        if (setup(points, polygonName)) {
            break;
        }

        cout << "Da giac khong hop le. Vui long nhap lai toa do cac diem.\n";
    }
}
