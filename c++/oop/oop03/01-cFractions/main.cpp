/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>

#include "cFractions.h"

using namespace std;

int main() {
    cFractions listFractions("DANH SACH CAC PHAN SO");

    cout << "===== CHUONG TRINH NHAP DANH SACH PHAN SO =====\n\n";

    listFractions.input();

    cout << "\n===== DANH SACH BAN DA NHAP =====\n";
    listFractions.output();

    cout << "\n===== CAC KET QUA XU LY =====\n";

    cout << "Tong cac phan so: ";
    listFractions.sum().output();
    cout << "\n";

    cout << "Phan so lon nhat: ";
    listFractions.findMax().output();
    cout << "\n";

    cout << "Phan so nho nhat: ";
    listFractions.findMin().output();
    cout << "\n";

    cout << "Phan so co tu so nguyen to lon nhat: ";
    listFractions.findLargestPrimeNumerator().output();
    cout << "\n";

    cFractions ascending = listFractions;
    ascending.sortAscending();
    cout << "\n";
    ascending.outputCompact("tang dan");

    cFractions descending = listFractions;
    descending.sortDescending();
    descending.outputCompact("giam dan");

    return 0;
}