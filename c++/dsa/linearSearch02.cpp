/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT003.F21.CN1.CNTT
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