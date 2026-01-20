#include <iostream>
using namespace std;

/**

input:
    + int arr []
    + int n
output:
    + return bool true
**/
bool toCheckSysmetry(float arr[], int n)
{
    for(int i = 0; i < n/2; i++){
        if(arr[i] != arr[n-1-i]){
            return false;
        }
    }
    return true;

}

int main()
{
    float arr[] = {1, 2, 3.1, 7.3, 10, 10,7.3, 3.1, 2, 1};
    int n = 10;
    if (toCheckSysmetry(arr,n)) {
        cout << "The array is symmetrical." << endl;
    } else {
        cout << "The array is not symmetrical." << endl;
    }
    return 0;
}
