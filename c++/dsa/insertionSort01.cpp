/*
================================================================================
Insertion Sort - Sắp xếp GIẢM DẦN
================================================================================
Dựa vào đoạn code mẫu trong slide bài giảng, hãy cài đặt và tùy chỉnh thuật toán sắp xếp InsertionSort để sắp xếp mảng số nguyên A theo trật tự giảm dần và in ra màn hình theo mẫu ví dụ.

Input:
- Dòng đầu tiên là số nguyên N dương (0 < N < 200)
- Dòng tiếp theo chứa N số nguyên (với giá trị mỗi số nguyên nhỏ hơn 2 * 10^9) là các phần tử của mảng A

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
i = 1
Mang truoc khi xu ly: 3 0 8 2 1 4 7
Phan tu dang xet A[1] = 0
Chen 0 vao vi tri k = 1
Mang sau khi xu ly: 3 0 8 2 1 4 7
... (Tương tự cho các bước i tiếp theo) ...
Mang sau khi sap xep:
8 7 4 3 2 1 0
*/
#include <iostream>
#include <vector>

using namespace std;

// Hàm hỗ trợ in mảng
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

    for (int i = 1; i < n; ++i) {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi xu ly: ";
        printArray(a);

        long long key = a[i];
        cout << "Phan tu dang xet A[" << i << "] = " << key << "\n";

        int j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        int k = j + 1;
        a[k] = key;

        cout << "Chen " << key << " vao vi tri k = " << k << "\n";
        cout << "Mang sau khi xu ly: ";
        printArray(a);

        if (i < n - 1) {
            cout << "\n";
        }
    }

    cout << "\nMang sau khi sap xep:\n";
    printArray(a);

    return 0;
}