/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>

#include "cComplex.h"

int main() {
    cComplex first;
    cComplex second;

    std::cout << "Nhập số phức thứ nhất\n";
    first.input();

    std::cout << "\nNhập số phức thứ hai\n";
    second.input();

    cComplex sum = first.add(second);
    cComplex difference = first.subtract(second);
    cComplex product = first.multiply(second);

    std::cout << "\nSố phức thứ nhất: ";
    first.output();
    std::cout << "\nSố phức thứ hai: ";
    second.output();

    std::cout << "\n\nTổng: ";
    sum.output();

    std::cout << "\nHiệu: ";
    difference.output();

    std::cout << "\nTích: ";
    product.output();

    std::cout << "\nThương: ";
    if (second.isZero()) {
        std::cout << "không xác định (chia cho số phức 0)";
    } else {
        cComplex quotient = first.divide(second);
        quotient.output();
    }

    std::cout << "\n";
    return 0;
}
