/*
================================================================================
Selection Sort - Sắp xếp GIẢM DẦN
================================================================================
Dựa vào đoạn code mẫu trong slide bài giảng, hãy cài đặt và tùy chỉnh thuật toán sắp xếp SelectionSort để sắp xếp mảng số nguyên A theo trật tự giảm dần và in ra màn hình theo mẫu ví dụ.

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
i = 0
Mang truoc khi swap: 3 0 8 2 1 4 7
Phan tu lon nhat trong doan [1, 6]: 8
Swap 3 va 8
Mang sau khi swap: 8 0 3 2 1 4 7
...
Mang sau khi sap xep:
8 7 4 3 2 1 0
*/
#include <iostream>
#include <vector>

using namespace std;

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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    printArray(a);
    cout << "\nSap xep:\n";

    // Thuật toán Selection Sort (Giảm dần)
    for (int i = 0; i < n - 1; ++i) {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi swap: ";
        printArray(a);

        int max_idx = i;
        // Tìm phần tử lớn nhất trong đoạn [i+1, n-1]
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[max_idx]) {
                max_idx = j;
            }
        }

        cout << "Phan tu lon nhat trong doan [" << i + 1 << ", " << n - 1 << "]: " << a[max_idx] << "\n";
        cout << "Swap " << a[i] << " va " << a[max_idx] << "\n";
        
        swap(a[i], a[max_idx]);
        
        cout << "Mang sau khi swap: ";
        printArray(a);

        if (i < n - 2) {
            cout << "\n";
        }
    }

    cout << "\nMang sau khi sap xep:\n";
    printArray(a);

    return 0;
}