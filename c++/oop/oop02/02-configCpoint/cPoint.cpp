/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPoint.h"

#include <cctype>
#include <sstream>
#include <string>

using namespace std;

namespace {
// Cat bo khoang trang o dau va cuoi chuoi.
string trim(const string& text) {
    size_t left = 0;
    while (left < text.size() && isspace(static_cast<unsigned char>(text[left]))) {
        ++left;
    }

    size_t right = text.size();
    while (right > left && isspace(static_cast<unsigned char>(text[right - 1]))) {
        --right;
    }

    return text.substr(left, right - left);
}

// Chuyen chuoi thanh so thuc va kiem tra ky tu du.
bool parseNumber(const string& text, double& value) {
    stringstream stream(text);
    char extra = '\0';
    // So hop le chi duoc phep co mot gia tri so, khong co ky tu du.
    return (stream >> value) && !(stream >> extra);
}

// Doc va kiem tra toa do diem theo cac dang hop le.
bool readPoint(const char* prompt, double& x, double& y) {
    string line;

    while (true) {
        cout << prompt;
        if (!getline(cin >> ws, line)) {
            return false;
        }

        string compact = trim(line);
        if (!compact.empty() && compact.front() == '(' && compact.back() == ')') {
            compact = trim(compact.substr(1, compact.size() - 2));
        }

        size_t commaPos = compact.find(',');
        if (commaPos != string::npos) {
            // Neu co dau phay, du lieu phai la dang x,y va chi co mot dau phay.
            if (compact.find(',', commaPos + 1) != string::npos) {
                cout << "Sai định dạng tọa độ, hãy nhập (x, y), x,y hoặc x y.\n";
                continue;
            }

            string left = trim(compact.substr(0, commaPos));
            string right = trim(compact.substr(commaPos + 1));

            if (parseNumber(left, x) && parseNumber(right, y)) {
                return true;
            }

            cout << "Sai giá trị tọa độ, hãy dùng dấu chấm cho số thập phân.\n";
            continue;
        }

        stringstream stream(compact);
        char extra = '\0';
        // Truong hop cach nhau bang khoang trang: x y.
        if (stream >> x >> y && !(stream >> extra)) {
            return true;
        }

        cout << "Sai định dạng tọa độ, hãy nhập (x, y), x,y hoặc x y.\n";
    }
}
}  // namespace

// Khoi tao diem mac dinh tai goc toa do.
cPoint::cPoint() : x(0.0), y(0.0) {}

// Khoi tao diem tu hai toa do x, y.
cPoint::cPoint(double x, double y) {
    setValue(x, y);
}

// Ham sao chep diem.
cPoint::cPoint(const cPoint& other) : x(other.x), y(other.y) {}

// Gan dong thoi x va y.
void cPoint::setValue(double newX, double newY) {
    x = newX;
    y = newY;
}

// Gan hoanh do x.
void cPoint::setX(double newX) {
    x = newX;
}

// Gan tung do y.
void cPoint::setY(double newY) {
    y = newY;
}

// Lay hoanh do x.
double cPoint::getX() const {
    return x;
}

// Lay tung do y.
double cPoint::getY() const {
    return y;
}

// Tinh tien diem theo vector (dx, dy).
void cPoint::translate(double dx, double dy) {
    x += dx;
    y += dy;
}

// Nhap toa do diem.
void cPoint::input() {
    readPoint("Nhập tọa độ điểm (x, y): ", x, y);
}

// In diem theo dang (x, y).
void cPoint::output() const {
    cout << "(" << x << ", " << y << ")";
}
