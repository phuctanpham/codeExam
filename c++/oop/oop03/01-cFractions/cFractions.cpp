/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cFractions.h"

#include <iostream>
#include <sstream>

using namespace std;

namespace {
bool readCount(const string& prompt, int& count) {
    string line;

    while (true) {
        cout << prompt;
        if (!getline(cin >> ws, line)) {
            return false;
        }

        stringstream stream(line);
        char extra = '\0';
        if (!(stream >> count) || (stream >> extra) || count < 0) {
            cout << "So luong khong hop le, vui long nhap lai.\n";
            continue;
        }

        return true;
    }
}
}

int cFractions::instanceCount = 0;

// Phan dinh nghia doi tuong va thanh phan static
cFractions::cFractions() : title("DANH SACH PHAN SO") {
    ++instanceCount;
}

cFractions::cFractions(const string& title) : title(title) {
    ++instanceCount;
}

int cFractions::getInstanceCount() {
    return instanceCount;
}

// Input block
void cFractions::input() {
    int count = 0;

    if (!readCount("Nhap so luong phan so: ", count)) {
        return;
    }

    fractions.clear();
    fractions.reserve(static_cast<size_t>(count));

    for (int i = 0; i < count; ++i) {
        cFraction fraction;
        fraction.input("  Phan so " + to_string(i + 1) + " (a/b): ");
        fractions.push_back(fraction);
    }
}

// Output block
void cFractions::output() const {
    cout << "\n" << title << "\n";
    cout << "So phan so: " << fractions.size() << "\n";

    for (size_t i = 0; i < fractions.size(); ++i) {
        cout << "  [" << i + 1 << "] ";
        fractions[i].output();
        cout << "\n";
    }
}

void cFractions::outputCompact(const string& label) const {
    cout << label << ": {";

    for (size_t i = 0; i < fractions.size(); ++i) {
        if (i > 0) {
            cout << ';';
        }

        fractions[i].output();
    }

    cout << "}\n";
}

size_t cFractions::size() const {
    return fractions.size();
}