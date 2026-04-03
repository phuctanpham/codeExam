/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>

#include "cFraction.h"

using namespace std;

int main() {
    cFraction fraction1;
    cFraction fraction2;

    cout << "Nhập phân số thứ nhất\n";
    fraction1.input();

    cout << "Nhập phân số thứ hai\n";
    fraction2.input();

    cFraction sum = fraction1.add(fraction2);
    cFraction difference = fraction1.subtract(fraction2);
    cFraction product = fraction1.multiply(fraction2);

    cout << "\nPhân số thứ nhất: ";
    fraction1.output();
    cout << "\nPhân số thứ hai: ";
    fraction2.output();

    cout << "\n\nTổng: ";
    sum.output();

    cout << "\nHiệu: ";
    difference.output();

    cout << "\nTích: ";
    product.output();

    cout << "\nThương: ";
    if (fraction2.getNumerator() == 0) {
        cout << "không xác định (chia cho phân số 0)";
    } else {
        cFraction quotient = fraction1.divide(fraction2);
        quotient.output();
    }

    cout << "\n";
    return 0;
}
