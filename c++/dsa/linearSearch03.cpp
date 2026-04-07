/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
*/
/*
Cho trước một mảng có N phần tử. Hãy in ra  MEXi với 0 ≤ i <n.
Biết rằng, MEXilà số nguyên nhỏ nhất lớn hơn hoặc bằng 0 mà không 
xuất hiện trong từ đầu mảng cho đến phần tử i.
Input:
 - Dòng đầu tiên là N (1 ≤ N ≤ 2×10ˆ5) thể hiện số phần tử của mảng
 - Dòng tiếp theo chứa N số nguyên là các phần tử của mảng
Output:
 - N số nguyên tương ứng với MEXi
 Ví dụ:
  - Input:
    5
    1 0 5 2 3
  - Output:
    0 2 2 3 4
  - Giải thích:
  	- Với i = 0, input {1}, số chưa xuất hiện đầu tiên tính từ 0 là 0.
    - Với i = 1, input {1, 0}, số chưa xuất hiện đầu tiên tính từ 0 là 2.
    - Với i = 2, input {1, 0, 5}, số chưa xuất hiện đầu tiên tính từ 0  là 2.
    - Với i = 3, input {1, 0, 5, 2}, số chưa xuất hiện đầu tiên tính từ 0  là 3.
    - Với i = 4, input {1, 0, 5, 2, 3}, số chưa xuất hiện đầu tiên tính từ 0  là 4.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  // Đọc số phần tử của mảng.
  cin >> n;

  // frequency[x] lưu số lần giá trị x đã xuất hiện trong đoạn đầu đang xét.
  vector<int> frequency(n + 1, 0);
  // Lưu trước toàn bộ đáp án để in ra một lần, giúp giảm chi phí I/O.
  vector<int> result(n);
  // mex là số nguyên không âm nhỏ nhất chưa xuất hiện.
  int mex = 0;

  for (int i = 0; i < n; i++) {
    int value;
    // Đọc từng phần tử và cập nhật trạng thái xuất hiện của nó.
    cin >> value;

    // Chỉ cần theo dõi các giá trị từ 0 đến n vì mex luôn nằm trong khoảng này.
    if (0 <= value && value <= n) {
      frequency[value]++;
    }

    // Tăng mex cho đến khi gặp một số chưa xuất hiện.
    while (mex <= n && frequency[mex] > 0) {
      mex++;
    }

    result[i] = mex;
  }

  // In kết quả theo dạng cách nhau bởi dấu cách.
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << ' ';
    cout << result[i];
  }

  return 0;
}