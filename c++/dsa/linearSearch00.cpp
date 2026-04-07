/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
//header
#include <iostream>
using namespace std;
int search(int arr[], int N, int x){
//body
    for (int k = 0; k < N; k++) {
        if (arr[k] == x) {
            return k;
        }
    }
    return -1;
//footer
}
int main(){
    int arr[100],n,x;
    cin>>n;
    for (int i = 0; i < n ; i++)    
        cin>>arr[i];
    cin>>x;
    cout<<search(arr, n, x)<<endl;
    return 0;
}