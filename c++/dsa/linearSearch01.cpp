/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
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