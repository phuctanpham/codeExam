/*
================================================================================
Merge Sort - Sắp xếp GIẢM DẦN
================================================================================
Dựa vào đoạn code mẫu trong slide bài giảng, hãy cài đặt và tùy chỉnh thuật toán sắp xếp MergeSort để sắp xếp mảng số nguyên A theo trật tự giảm dần và in ra màn hình theo mẫu ví dụ.

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
k = 1
Mang A (truoc khi chia): 3 0 8 2 1 4 7
Mang B: 3 8 1 7
Mang C: 0 2 4
Mang A (sau khi gop): 3 0 8 2 4 1 7
...
Mang sau khi sap xep:
8 7 4 3 2 1 0
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

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Mang truoc khi sap xep:\n";
    printArray(a);
    cout << "\nSap xep:\n";

    for (int k = 1; k < n; k *= 2) {
        cout << "k = " << k << "\n";
        cout << "Mang A (truoc khi chia): "; printArray(a);
        
        vector<long long> B, C;
        // Trích xuất các đoạn Left vào B, Right vào C
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = i; j < min(i + k, n); j++) B.push_back(a[j]);
            for (int j = i + k; j < min(i + 2 * k, n); j++) C.push_back(a[j]);
        }
        
        cout << "Mang B: "; printArray(B);
        if (!C.empty()) { cout << "Mang C: "; printArray(C); }
        else { cout << "Mang C:\n"; }
        
        int b_idx = 0, c_idx = 0, a_idx = 0;
        for (int i = 0; i < n; i += 2 * k) {
            int len1 = min(k, n - i);
            int len2 = max(0, min(k, n - i - k));
            int end_b = b_idx + len1;
            int end_c = c_idx + len2;
            
            // Gộp theo thứ tự giảm dần
            while (b_idx < end_b && c_idx < end_c) {
                if (B[b_idx] > C[c_idx]) {
                    a[a_idx++] = B[b_idx++];
                } else {
                    a[a_idx++] = C[c_idx++];
                }
            }
            while (b_idx < end_b) a[a_idx++] = B[b_idx++];
            while (c_idx < end_c) a[a_idx++] = C[c_idx++];
        }
        
        cout << "Mang A (sau khi gop): "; printArray(a);
        cout << "\n"; 
    }

    cout << "Mang sau khi sap xep:\n";
    printArray(a);

    return 0;
}