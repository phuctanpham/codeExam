#include <iostream>
using namespace std;
/*
input:
 + double element
 + int n
 + int arr[]
output:
 + return int arr[a] arr[b]
 
*/

bool isInteger(double n){
    if (n == int(n)){
        return true;
    }
    return false;
}

bool isElement(int arr[], int n, int element){
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

void toPrintPair(int arr[], int n, int element){
    int m = 0;
    for (int i = 0; i < n; i++ ) {
        if (isElement(arr, n, element - arr[i])){
            m++;
            cout << m << ".(" << arr[i] << ";" << element - arr[i] << ")" << endl;
        }
    }
}

void toPrintArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i]; 
    }
}

int main(){
    int arr[] = {1, 2, 8, 10, 11, 20, 5, 6, 7, 0};
    int n = 10;
    double element;
    cout << "Original Array:";
    toPrintArray(arr, n);
    cout << endl;
    cout << "Input an integer number: ";
    while (!(cin >> element) || !isInteger(element)) {
        cout << "That is not a whole integer. Please try again: ";
    }
    cout << "\nBelow are pairs of " << (int)element << ":" << endl;
    toPrintPair(arr, n, (int)element);
    return 0;
}