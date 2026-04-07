/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>
#include <limits>
#include <string>

#include "cPolynomial.h"

using namespace std;

void cPolynomial::input() {
    int n = 0;

    auto readInteger = [](int& value) {
        string token;
        if (!(cin >> token)) {
            return false;
        }

        size_t pos = 0;
        try {
            int parsed = stoi(token, &pos);
            if (pos != token.size()) {
                return false;
            }
            value = parsed;
            return true;
        } catch (...) {
            return false;
        }
    };

    while (true) {
        cout << "Nhap bac cua da thuc (cho phep n < 0): " << flush;
        if (readInteger(n)) {
            break;
        }

        if (cin.eof()) {
            return;
        }

        if (!cin.good()) {
            cin.clear();
        }
        cout << "Du lieu khong hop le. Vui long nhap so nguyen.\n";
    }

    if (n < 0) {
        // Negative degree is treated as the zero polynomial.
        setup({0.0}, polynomialName);
        return;
    }

    vector<double> coeffs(static_cast<size_t>(n) + 1, 0.0);

    for (int i = 0; i <= n; ++i) {
        int power = n - i;
        while (true) {
            cout << "Nhap he so cua x^" << power << ": " << flush;
            if (cin >> coeffs[static_cast<size_t>(i)]) {
                break;
            }

            if (cin.eof()) {
                return;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Du lieu khong hop le. Vui long nhap so thuc.\n";
        }
    }

    setup(coeffs, polynomialName);
}