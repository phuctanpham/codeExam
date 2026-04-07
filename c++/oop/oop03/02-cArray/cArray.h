/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_ARRAY_H
#define C_ARRAY_H

#include <string>
#include <vector>

using namespace std;

class cArray {
private:
    vector<int> data;
    string title;

    // Static component: count how many cArray objects were created.
    static int instanceCount;

public:
    cArray();
    explicit cArray(const string& title);

    static int getInstanceCount();

    void inputRandom();
    void output() const;
    int countValue(int value) const;
    bool isAscending() const;
    int findFractionMin() const;
    int findPrimeMax() const;
    void sortAscending();
    void sortDescending();

    size_t size() const;
    bool empty() const;
};

#endif