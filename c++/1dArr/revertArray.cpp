#include <iostream>
using namespace std;
/*
input:
    + float arr[]
    + int n
output:
    return arr[]
*/

// function of reverting array
void toRevert(float arr[], int n) {
    for(int i = 0; i < n/2; i++){
        swap(arr[i],arr[n-1-i]);
    }
}
// function of printing an array
void toPrintArray(float arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Main function
int main() {
    float arr[] = {0, 2, 3, -1, -3, -4, -10, -11, 8, 21,22};
    int n = 11;
    cout << "original array: ";
    toPrintArray(arr,n);
    toRevert(arr,n);
    cout << "\nReverted Result: ";
    toPrintArray(arr,n);
    return 0;
}