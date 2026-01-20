#include <iostream>
#include <cmath>
using namespace std;

/**

input:
    + float arr []
    + int n
output:
    + return true if at least one square number is found
**/
bool toCheckSquareNumber(float arr[], int n)
{
    for(int i = 0; i < n; i++){
        if (arr[i] >= 0 && sqrt(arr[i]) == int(sqrt(arr[i]))) {
            return true;
        }
    }
    return false;

}

int main()
{
    float arr[] = {1, 4, 3.1, 7.3, 10, 11, 17.3, 23.1, 32, 41};
    int n = 10;
    if (toCheckSquareNumber(arr,n)) {
        cout << "The array contains at least one square number." << endl;
    } else {
        cout << "The array does not contain a square number." << endl;
    }
    return 0;
}
