/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_FRACTIONS_H
#define C_FRACTIONS_H

#include <string>
#include <vector>

#include "cFraction.h"

using namespace std;

class cFractions {
private:
    vector<cFraction> fractions;
    string title;

    // Thanh phan static: dem so doi tuong cFractions da duoc tao.
    static int instanceCount;

public:
    cFractions();
    explicit cFractions(const string& title);

    // Ham truy xuat gia tri static.
    static int getInstanceCount();

    void input();
    void output() const;
    void outputCompact(const string& label) const;
    cFraction sum() const;
    cFraction findMax() const;
    cFraction findMin() const;
    cFraction findLargestPrimeNumerator() const;
    void sortAscending();
    void sortDescending();
    size_t size() const;
};

#endif