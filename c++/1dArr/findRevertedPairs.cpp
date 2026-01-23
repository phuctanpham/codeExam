#include <iostream>
using namespace std;
/*
To find pair of revert numbers. Example: {12, 0, 1, 10, 13, 31, 21, 34, 210}. Both (12,21) 
and (13,31) are expected outputs. Both (1,10) and (12, 210) are not expected outputs.
input:
 + int n
 + int arr[]
output:
 + return int& m 

*/
int revertedNumber(int n){
    int output = 0;
    while (n > 0){
        int lastNumber = n%10;
        output = output*10 + lastNumber;
        n = n/10;
    }
    return output;
}

bool isElement(int arr[], int n, int m){
    for(int i = 0; i < n; i++){
        if (arr[i] == m){
            return true;
        } 
    }
    return false;
}

void toFindRevertedPair(int arr[], int n){
    for(int i = 0; i < n; i++){
        if (arr[i] % 10 == 0) continue;
        for(int j = i + 1; j < n; j++) {
            if (arr[j] == revertedNumber(arr[i]) && arr[i] != arr[j]) {
               cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
            }
        }
    }
}

int main(){
    int arr[] = {1, 41, 3, 5, 52, 45, 3, 14, 25, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    toFindRevertedPair(arr,n);
    return 0;
}