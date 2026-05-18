/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
*/
/*
Cho một dãy số nguyên a gồm N phần tử a1, a2, …, aN.
Có Q truy vấn, mỗi truy vấn cho một số nguyên x. 
Bạn hãy trả lời xem số nguyên x này có trong dãy a hay không?
Lưu ý: Trong template đã đảm bảo mảng ban đầu sau khi nhập vào sẽ được sắp xếp, 
các bạn chỉ cần hoàn thành hàm myBinarySearch.
Input:
 - Dòng đầu tiên là 2 số nguyên dương N, Q (1 ≤ N, Q ≤ 105)
 - Dòng tiếp theo chứa N số nguyên ai (−109 ≤ ai ≤ 109) là các phần tử của mảng.
 - Q dòng tiếp theo, mỗi dòng chứa một số x là câu hỏi của truy vấn.
Output:
Gồm Q dòng, mỗi dòng gồm một câu trả lời. Nếu x trong dãy a thì in ra ‘YES'.
Ngược lại, in ra ‘NO'.
Ví dụ:
 - Input:
    - 7 5
    - 9 10 12 -1 0 1 7
    - 3
    - 2
    - 1
    - 9
    - 7
 - Output:
    - NO
    - NO
    - YES
    - YES
    - YES   

*/

// Header
#include <iostream>
#include <algorithm>
using namespace std;

bool myBinarySearch(int a[], int n, int x);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x; 
    while (q--){
        cin >> x;
        if (myBinarySearch(arr, n, x))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
// Body 
bool myBinarySearch(int a[], int n, int x){
    int left = 0;
    int right = n - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (a[mid] == x) return true;
        if (a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}

// Footer