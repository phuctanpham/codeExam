/*
================================================================================
QuickSort - Sắp xếp TĂNG DẦN
================================================================================
Dựa vào đoạn code mẫu trong slide bài giảng, hãy cài đặt và tùy chỉnh thuật toán sắp xếp QuickSort để sắp xếp mảng số nguyên A theo trật tự tăng dần và in ra màn hình theo mẫu ví dụ.

Input: 
- N dương (0 < N < 200) và N phần tử của mảng A (< 2*10^9)

Output: 
- In ra màn hình theo mẫu ví dụ

Ví dụ:
INPUT:
7
3 0 8 2 1 4 7

OUTPUT:
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep:
Truoc: 3 0 8 2 1 4 7
Left=0 - Right=6 - Pivot=2
Sau: 1 0 2 8 3 4 7

Truoc: 1 0 2 8 3 4 7
Left=0 - Right=2 - Pivot=0
Sau: 0 1 2 8 3 4 7
...
Mang sau khi sap xep:
0 1 2 3 4 7 8
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<long long>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i < a.size() - 1) cout << " ";
    }
    cout << "\n";
}

void QuickSortAsc(vector<long long>& a, int left, int right) {
    if (left >= right) return;
    
    cout << "Truoc: "; printArray(a);
    
    long long pivot = a[(left + right) / 2];
    cout << "Left=" << left << " - Right=" << right << " - Pivot=" << pivot << "\n";
    
    int i = left, j = right;
    while (i < j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    cout << "Sau: "; printArray(a);
    cout << "\n";
    
    if (left < j) QuickSortAsc(a, left, j);
    if (i < right) QuickSortAsc(a, i, right);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Mang truoc khi sap xep:\n";
    printArray(a);
    cout << "\nSap xep:\n";

    QuickSortAsc(a, 0, n - 1);

    cout << "Mang sau khi sap xep:\n";
    printArray(a);

    return 0;
}