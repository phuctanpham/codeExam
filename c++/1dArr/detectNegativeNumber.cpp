#include <iostream>
using namespace std;
/*
input:
    + float arr[]
    + int n
output:
    return float negative[]
*/
// function of negative number dectection
bool isNegative(float n) {
    if (n < 0) {
        return true;
    }
    return false;
}
// function of negative number collection
int toCollectNegative(float arr[], int n) {
    int m = 0;
    for(int i = 0; i < n; i++){
        if (isNegative(arr[i])){
            arr[m] = arr[i];
            m++;
        }
    }
    return m;
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
    float arr[] = {0, 2, 3, -1, -3, -4, -10, -11, 8, 21};
    int n = 10;
    cout << "original array: ";
    toPrintArray(arr,n);
    int m = toCollectNegative(arr,n);
    cout << "\nThere are " << m << " negative numbers: ";
    toPrintArray(arr,m);
    return 0;
}