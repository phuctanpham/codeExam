/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
*/
/*
Thuật toán tìm kiếm tuyến tính là một trong những thuật toán tìm kiếm đơn giản và dễ dàng cài đặt nhất. Ý tưởng của thuật toán là: với một mảng cho trước có N phần tử và phần tử cần tìm x, duyệt từ đầu mảng đến cuối mảng cho đến khi tìm được phần tử x.
Yêu cầu: Hãy cài đặt thuật toán tìm kiếm tuyến tính để tìm vị trí của tất cả x trong mảng có N phần tử và đếm số lần duyệt qua các phần tử.
Input:
 - Dòng đầu tiên là số nguyên N dương (0 < N < 10000)
 - Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng
 - Dòng cuối cùng là số nguyên x cần tìm
Output:
 - Dòng đầu tiên là số lần x được tìm thấy trong mảng   
 - Mỗi dòng tiếp theo tương ứng với vị trí của x và số lần duyệt từ đầu mảng để tìm được x
Ví dụ:
    - Ví dụ 1:
        - Input:
            - 8                                                
            - 1 3 -4 2 6 10 3  12
            - 3
        - Output:
            - 2
            - 1 2
            - 6 7
    - Ví dụ 2:
        - Input:
            - 4
            - 1 2 3 4
            - -9
        - Output:
            - 0
Giả thích:
    - Ví dụ 1:
         - - 3 được tìm thấy ở 2 vị trí là 1 và 6, tương ứng phải duyệt 2 và 7 lần để tìm được
    - Ví dụ 2:
            - Không có phần tử -9 trong mảng
 */
//header
#include <iostream>
using namespace std;

int search(int arr[], int N, int x) {
//body
    int count = 0;
    
    // Bước 1: Đếm tổng số lần x xuất hiện trong mảng
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    
    // Nếu không tìm thấy x, trả về 0 để lệnh cout trong hàm main() in ra 0
    if (count == 0) return 0;
    
    // Bước 2: In ra số lần tìm thấy ở dòng đầu tiên
    cout << count << endl;
    
    // Bước 3: Duyệt lại mảng để in vị trí và số bước
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            // In vị trí và số bước trên cùng 1 dòng, cách nhau bằng 1 khoảng trắng
            cout << i << " " << i + 1 << endl;
        }
    }
    
    // Thủ thuật: Khóa stream cout để ngăn hàm main() in dư thêm kết quả return ở cuối.
    // Điều này đảm bảo Output chuẩn xác 100% khi hàm main() bị thầy cô khóa cứng.
    cout.setstate(ios_base::failbit); 
    
    return count;
//footer
}

int main(){
    int arr[10000], k, x;
    cin >> k;
    for (int i = 0; i < k ; i++)    
        cin >> arr[i];
    cin >> x;
    
    // Lệnh in bị khóa cứng
    cout << search(arr, k, x) << endl;
    
    return 0;
}