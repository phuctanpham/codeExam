#include <iostream>
using namespace std;

/**

input:
    + float arr []
    + int n
    + float value 
output:
    + return bool true
**/
bool toFindAValue(float arr[], int n, float value)
{
    for(int i = 0; i < n; i++){
        if(arr[i] == value){
            return true;
        }
    }
    return false;

}

int main()
{
    float arr[] = {1, 2, 3.1, 7.3, 10, 11,17.3, 23.1, 32, 41};
    int n = 10;
    float value;
    cout << "Enter the value to find: ";
    cin >> value;
    cout << value;
    if (toFindAValue(arr,n,value)) {
        cout << "\n=> The value " << value << " exists in the array." << endl;
    } else {
        cout << "\n=> The value " << value << " does not exist in the array." <<  endl;
    }
    return 0;
}
