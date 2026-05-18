/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
*/
/*
Thuật toán tìm kiếm tuyến tính là một trong những thuật toán tìm kiếm đơn giản và dễ dàng cài đặt nhất. Ý tưởng của thuật toán là: với một mảng cho trước có N phần tử và phần tử cần tìm x, duyệt từ đầu mảng đến cuối mảng cho đến khi tìm được phần tử x.
Yêu cầu: Hãy cài đặt thuật toán tìm kiếm tuyến tính để tìm vị trí của x đầu tiên trong mảng có N phần tử và đếm số lần duyệt qua các phần tử.
Input:
 - Dòng đầu tiên là số nguyên N dương (0 < N < 10000)
 - Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng
 - Dòng cuối cùng là số nguyên x cần tìm
Output:
 - Dòng đầu tiên là vị trí của x đầu tiên trong mảng nếu tìm được. Nếu không tìm thấy thì xuất ra -1
 - Số lần duyệt qua các phần tử của mảng (từ đầu mảng đến cuối) để tìm được x
 - Dòng thứ ba là vị trí của x đầu tiên trong mảng (đếm từ cuối đến đầu) nếu tìm được. Nếu không tìm thấy thì xuất ra -1
 - Số lần duyệt qua các phần tử của mảng (từ cuối mảng đến đầu) để tìm được x
 - Nếu như ở 2 dòng đầu tiên mà không tìm thấy thì không cần xuất ra 2 dòng tiếp theo
Ví dụ:
 - Ví dụ 1:
    - Input:
        - 5                                                  
        - 1 -4 3 2 6
        - -4
    - Output:
        - 1
        - 2
        - 3
        - 4
 - Ví dụ 2:
    - Input:
        - 4
        - 1 2 3 4
        - -9
    - Output:
        - -1
Giả thích:
    - Ví dụ 1:
         - 4 ở vị trí 1 tính từ đầu mảng
         - phải duyệt qua 2 lần để tìm được -4
         - -4 ở vị trí 3 tính từ cuối mảng
         - phải duyệt qua 4 lần từ cuối mảng để tìm được -4
    - Ví dụ 2:
            - Không có phần tử -9 trong mảng
 */

//header
#include <iostream>
using namespace std;

// Dùng 3 tham chiếu để hứng: số bước xuôi, vị trí ngược, số bước ngược
int search(int arr[], int N, int x, int& steps_start, int& pos_end, int& steps_end) {
//body
    int pos_start = -1; // Biến duy nhất để lưu vị trí xuôi
    
    // 1. Vòng lặp duyệt tiến
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            pos_start = i;       // Lưu vị trí
            steps_start = i + 1; // Gán số bước cho tham chiếu
            break;               // Bắt buộc dùng break, không dùng return để đi tiếp xuống dưới
        }
    }

    // Nếu không tìm thấy ở lần lặp đầu, return -1 luôn để tiết kiệm thời gian
    if (pos_start == -1) return -1; 

    // 2. Vòng lặp duyệt lùi (tái sử dụng biến i)
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] == x) {
            pos_end = (N - 1) - i; // Gán vị trí ngược cho tham chiếu
            steps_end = N - i;     // Gán số bước ngược cho tham chiếu
            break;
        }
    }
    
    // Trả về vị trí xuôi qua lệnh return
    return pos_start;
//footer
}

int main(){
    int arr[10000], k, x;
    cin >> k;
    for (int i = 0; i < k ; i++)    
        cin >> arr[i];
    cin >> x;
    
    // Khai báo các biến để hứng giá trị từ hàm (thông qua tham chiếu)
    int steps_start, pos_end, steps_end;
    
    // Gọi hàm và nhận giá trị trả về
    int pos_start = search(arr, k, x, steps_start, pos_end, steps_end);
    
    // In kết quả
    if (pos_start != -1) {
        cout << pos_start << endl;
        cout << steps_start << endl;
        cout << pos_end << endl;
        cout << steps_end << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}