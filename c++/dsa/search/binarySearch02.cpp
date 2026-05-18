/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
*/
/*
Thuật toán tìm kiếm nhị phân là một thuật toán tìm kiếm đơn giản nhưng có tốc độ tìm kiếm cực kỳ nhanh. Tuy nhiên, đa phần các hướng dẫn và khóa học trên mạng đều hướng dẫn người học cài đặt trên mảng số nguyên trong khi trong thực tế chỉ cần mảng có thể sắp xếp được thì ra có thể áp dụng thuật toán tìm kiếm nhị phân.
Hãy cài đặt thuật toán tìm kiếm nhị phân trên mảng chuỗi có N phần tử.

Input:
 - Dòng đầu tiên là số nguyên N dương (0 < N < 2000)
 - N dòng tiếp theo chứa các phần tử Ai trong mảng, mỗi phần tử là một chuỗi với độ dài không quá 10. Các phần tử này đã được sắp xếp theo thứ tự bảng chữ cái
 - Dòng cuối cùng là chuỗi x cần tìm

Output:
 - Dòng đầu tiên là vị trí của x được tìm thấy trong mảng. Nếu không tìm thấy thì xuất ra -1
 - Dòng tiếp theo là số lần duyệt qua các phần tử để tìm được x. Nếu không tìm thấy thì không cần xuất ra dòng này

 Ví dụ:
 - Ví dụ 1:
    - Input:
        - 8
        - 2024                                            
        - Cau
        - Giai
        - Lieu
        - Thuat
        - Va
        - du
        - truc
        - Va
    - Output:
        - 5
        - 2
 - Ví dụ 2:
    - Input:
        - 4
        - 2024
        - Happy
        - New
        - Year
        - 2023
    - Output:
        - -1
Giải thích:
 - Ví dụ 1:
    - 'Va' được tìm thấy ở vị trí 5
    - để tìm được 'Va' cần phải duyệt qua 2 vị trí là 3 và 5
 - Ví dụ 2:
    - không tìm thấy
 */

// Header
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string *a = new string[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    string target;
    cin >> target;

    int left = 0;
    int right = n - 1;
    int count = 0;
    int found = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        ++count;

        if (a[mid] == target) {
            found = mid;
            break;
        }

        if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << found;
    if (found != -1) {
        cout << '\n' << count;
    }

    delete[] a;
    return 0;
}

// Footer