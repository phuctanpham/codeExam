/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
*/
/*
Thuật toán tìm kiếm nhị phân là một thuật toán tìm kiếm đơn giản nhưng có tốc độ tìm kiếm cực kỳ nhanh.
Ý tưởng của thuật toán là: với một mảng N phần tử đã được sắp xếp (tăng dần/hoặc giảm dần tùy theo người ra đề) và số nguyên x cần tìm, ta sẽ thực hiện tìm kiếm ở miền có khả năng xuất hiện x sau mỗi lần lặp.
Hãy cài đặt thuật toán tìm kiếm nhị phân để tìm vị trí của phần tử x trong mảng có N phần tử và đếm số lần duyệt qua các phần tử.
Input:
 - Dòng đầu tiên là số nguyên N dương (0 < N < 32000)
 - Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng đã được sắp xếp tăng dần và không trùng nhau
 - Dòng cuối cùng là số nguyên x cần tìm
Output:
  - Dòng đầu tiên là vị trí của x được tìm thấy trong mảng. Nếu không tìm thấy thì xuất ra -1
  - Dòng tiếp theo là số lần duyệt qua các phần tử để tìm được x. Nếu không tìm thấy thì không cần xuất ra dòng này
Ví dụ 1:
 - Input:
    - 8
    - 1 3 4 5 10 12 15 20
    - 4
 - Output:
    - 2
    - 3
Ví dụ 2:
 - Input:
    - 4
    - 1 2 3 4
    - -9
 - Output:
    - -1
Giải thích:
 - Ví dụ 1:
    - 4 được tìm thấy ở vị trí 2
    - để tìm được 3 cần phải duyệt qua các phần tử ở vị trí 3, 1 và 2.
 - Ví dụ 2:
    - không tìm thấy -9 trong mảng

Lưu ý: Số lần duyệt để tìm x trong bài sẽ dựa trên pseudo code (mã giả) sau đây:

function binary_search(A, n, T) is
    L := 0
    R := n - 1
    while L <= R do
        m := floor((L + R) / 2)
        if A[m] < T then
            L := m + 1
        else if A[m] > T then
            R := m - 1
        else:
            return m
    return unsuccessful
*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& a, int target, int& count) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        ++count;

        if (a[mid] < target) {
            left = mid + 1;
        } else if (a[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int target;
    cin >> target;

    int count = 0;
    int found = binarySearch(a, target, count);

    cout << found;
    if (found != -1) {
        cout << '\n' << count;
    }
    return 0;
}