/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
*/
/*
Trọng số của một mảng được định nghĩa là sự khác biệt giữa phần tử lớn nhất và nhỏ nhất của mảng. Ví dụ: trọng số của mảng [3, 7, 1, 2] là (7 - 1) = 6, trọng số của mảng [2] là (2 - 2) = 0, trọng số của mảng trống là 0.
Cho một mảng A có độ dài N. Bạn phải chia các phần tử của A thành hai dãy con S1 và S2 (một trong S1, S2 có thể trống) sao cho:
 - Mỗi phần tử của mảng A chỉ thuộc một trong hai dãy S1 hoặc S2.
 - Tổng trọng số của hai dãy S1 và S2 là lớn nhất.
Bạn in ra đáp án lớn nhất có thể của tổng trọng số của hai dãy S1 và S2.

Input:
  - Dòng đầu tiên chứa N là kích thước của mảng A.
  - Dòng thứ hai chứa N số nguyên A[1], A[2],....., A[N] - biểu thị các phần tử của A.
Ràng buộc:
  - 1 <= T <= 10^4
  - 2 <= N <= 10^5
  - 1 <= A[i] <= 10^9
  - Tổng của N trên tất cả các test case không quá 2x10^5
Output:
  - Đối với mỗi trường hợp thử nghiệm, hãy in tổng trọng số tối đa có thể có của hai dãy con.
Ví dụ:
 - Input:
    - 2                  
    - 3
    - 1 2 3
    - 5
    - 4 8 1 10 2
 - Output:
    - 2
    - 15
    - Một phép chia có thể là [1, 3], [2] Ở đây tổng trọng số là = (3 - 1) + (2 - 2) = 2
    - Ở testcase số 2, có thể chia thành 2 dãy [4, 1, 10] và [8, 2] thì tổng trọng số là (10 - 1) + (8 - 2) = 15
*/

#include <cstdio>
#include <climits>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        long long mn1 = LLONG_MAX, mn2 = LLONG_MAX;
        long long mx1 = LLONG_MIN, mx2 = LLONG_MIN;

        for (int i = 0; i < n; ++i) {
            long long x;
            scanf("%lld", &x);

            if (x <= mn1) {
                mn2 = mn1;
                mn1 = x;
            } else if (x < mn2) {
                mn2 = x;
            }

            if (x >= mx1) {
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx2 = x;
            }
        }

        long long ans;
        if (n == 2) {
            ans = mx1 - mn1;
        } else {
            ans = (mx1 - mn2) + (mx2 - mn1);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
