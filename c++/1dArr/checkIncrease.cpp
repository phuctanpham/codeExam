#include <iostream>
using namespace std;

/**

input:
    + int arr []
    + int n
output:
    + return bool true
**/
bool toCheckIncrease(float arr[], int n)
{
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;

}

int main()
{
    float arr[] = {1, 2, 3.1, 7.3, 10, 11,17.3, 23.1, 32, 41};
    int n = 10;
    if (toCheckIncrease(arr,n)) {
        cout << "The array is increasing." << endl;
    } else {
        cout << "The array is not increasing." << endl;
    }
    return 0;
}
