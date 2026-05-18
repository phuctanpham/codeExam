/*
================================================================================
HeapSort - Sắp xếp TĂNG DẦN
================================================================================
Dựa vào đoạn code mẫu trong slide bài giảng, hãy cài đặt và tùy chỉnh thuật toán sắp xếp HeapSort để sắp xếp mảng số nguyên A theo trật tự tăng dần và in ra màn hình theo mẫu ví dụ.

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
Mang sau khi BuildHeap: 8 2 7 0 1 4 3
Swap 8 va 3
Mang sau khi heapify voi n = 6: 7 2 4 0 1 3 | 8
Swap 7 va 3
Mang sau khi heapify voi n = 5: 4 2 3 0 1 | 7 8
...
Mang sau khi sap xep:
0 1 2 3 4 7 8
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<long long>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<long long>& a, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, n, i);
    }
}

void printArray(const vector<long long>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i < a.size() - 1) cout << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Mang truoc khi sap xep:\n";
    printArray(a);
    cout << "\nSap xep:\n";

    buildHeap(a, n);
    cout << "Mang sau khi BuildHeap: "; printArray(a);

    for (int i = n - 1; i > 0; --i) {
        cout << "Swap " << a[0] << " va " << a[i] << "\n";
        swap(a[0], a[i]);
        heapify(a, i, 0);
        cout << "Mang sau khi heapify voi n = " << i << ": ";
        for (int j = 0; j < n; ++j) {
            if (j == i) cout << "| ";
            cout << a[j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    cout << "Mang sau khi sap xep:\n";
    printArray(a);

    return 0;
}