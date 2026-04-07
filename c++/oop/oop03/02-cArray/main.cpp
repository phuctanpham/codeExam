/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>

#include "cArray.h"

using namespace std;

int main() {
    cArray integerArray("DANH SACH SO NGUYEN NGAU NHIEN");

    cout << "===== CHUONG TRINH cArray - MANG 1 CHIEU =====\n\n";

    integerArray.inputRandom();

    cout << "\n===== cArrayExport.cpp =====\n";
    integerArray.output();

    int x = 0;
    cout << "\nNhap gia tri x can dem: ";
    cin >> x;
    cout << "\n===== cArrayCount.cpp =====\n";
    cout << "So lan xuat hien cua " << x << ": " << integerArray.countValue(x) << "\n";

    cout << "\n===== cArrayAscend.cpp (check) =====\n";
    cout << "Mang dang tang dan: " << (integerArray.isAscending() ? "Co" : "Khong") << "\n";

    cout << "\n===== cArrayFractionMin.cpp =====\n";
    cout << "Gia tri nho nhat: " << integerArray.findFractionMin() << "\n";

    cout << "\n===== cArrayPrimeMax.cpp =====\n";
    int maxPrime = integerArray.findPrimeMax();
    if (maxPrime == -1) {
        cout << "Khong co so nguyen to trong mang.\n";
    } else {
        cout << "So nguyen to lon nhat: " << maxPrime << "\n";
    }

    cArray ascendingArray = integerArray;
    ascendingArray.sortAscending();
    cout << "\n===== cArrayAscend.cpp (heap sort) =====\n";
    ascendingArray.output();

    cArray descendingArray = integerArray;
    descendingArray.sortDescending();
    cout << "\n===== cArrayDescend.cpp (insertion sort) =====\n";
    descendingArray.output();

    return 0;
}
