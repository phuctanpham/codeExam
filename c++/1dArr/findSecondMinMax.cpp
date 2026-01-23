#include <iostream>
using namespace std;
/*
To find the second maximum and the second minimum of an array
input:
 + int n
 + int arr[]
output:
 + return int& m 

*/
void ndMaxNumber(int arr[], int n, int& ndmax, int& ndmin){
    int m = arr[0];
    int k = arr[0];
    for(int i = 0; i < n; i++){
        if(m < arr[i]){
            m = arr[i];
        }
        if(k > arr[i]){
           k = arr[i]; 
        } 
    }    
    ndmax = k;
    ndmin = m;
    for(int i = 0; i < n; i++){
        if (ndmax < arr[i] && m != arr[i]){
            ndmax = arr[i];
        }
        if (ndmin > arr[i] && k != arr[i]){
            ndmin = arr[i];
        }
    }
}

int main(){
    int arr[] = {1, 4, 3, 5, 52, 45, 3, 1, 53, 10};
    int n = 10;
    int ndmax, ndmin;
    ndMaxNumber(arr, n, ndmax, ndmin);
    
    cout << "Second Max: " << ndmax << endl;
    cout << "Second Min: " << ndmin << endl;
    
    return 0;
}