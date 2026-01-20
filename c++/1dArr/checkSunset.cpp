#include <iostream>
using namespace std;

/**

input:
    + float arr[]
    + float sunset[]
    + int n
    + int m
output:
    + return bool
**/
bool toCheckSunset(float arr[], int n, float sunset[], int m) {
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (sunset[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main()
{
    float arr[] = {1, 2, 3.1, 7.3, 10, 11, 17.3, 23.1, 32, 41};
    int n = 10;
    float sunset[] = {1, 3.2, 3.1};
    int m = 3;
    if (toCheckSunset(arr, n, sunset, m)) {
        cout << "The sunset belongs to the array." << endl;
    } else {
        cout << "The sunset does not belong to the array." << endl;
    }
    return 0;
}
