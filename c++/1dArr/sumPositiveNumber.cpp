#include <iostream>
using namespace std;
/*
input:
    + float arr[]
    + int n
    + int& sum
output:
    return int sum
*/
// function of positive number dectection
bool isPositive(float n) {
    if (n > 0) {
        return true;
    }
    return false;
}
// function of positive number collection
int toCollectPositive(float arr[], int n, int& sum) {
    int m = 0;
    for(int i = 0; i < n; i++){
        if (isPositive(arr[i])){
            arr[m] = arr[i];
            m++;
            sum += arr[i];
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
    int sum = 0;
    cout << "original array: ";
    toPrintArray(arr,n);
    int m = toCollectPositive(arr,n,sum);
    cout << "\nThere are " << m << " positive numbers: ";
    toPrintArray(arr,m);
    cout << "\nTotal: " << sum << endl;
    return 0;
}