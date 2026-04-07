/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cArray.h"

#include <iostream>
#include <random>
#include <sstream>

using namespace std;

namespace {
bool readInteger(const string& prompt, int& value) {
    string line;

    while (true) {
        cout << prompt;
        if (!getline(cin >> ws, line)) {
            return false;
        }

        stringstream stream(line);
        char extra = '\0';
        if (!(stream >> value) || (stream >> extra)) {
            cout << "Gia tri khong hop le, vui long nhap lai.\n";
            continue;
        }

        return true;
    }
}
}

void cArray::inputRandom() {
    int n = 0;
    const int minValue = 0;
    const int maxValue = 99;

    while (true) {
        if (!readInteger("Nhap so phan tu n: ", n)) {
            return;
        }

        if (n <= 9 || n >= 99) {
            cout << "n phai thoa 9 < n < 99, vui long nhap lai.\n";
            continue;
        }

        break;
    }

    data.clear();
    data.reserve(static_cast<size_t>(n));

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(minValue, maxValue);

    for (int i = 0; i < n; ++i) {
        data.push_back(distribution(generator));
    }
}
