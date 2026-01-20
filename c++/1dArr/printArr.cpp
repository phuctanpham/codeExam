#include <iostream>
using namespace std;

/**
To create a double array by below value:
| 0.8 | 5.6 | 9.1 | 7.3 | 10 | 5.9 | 7.2 | 9.3 | 8.0 | 8.7 |

input:
    + float arr []
    + int n
output:
    + return float arr[]
**/
void toPrint(float arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }

}

int main()
{
    float arr[] = {0.8, 5.6, 9.1, 7.3, 10, 5.9, 7.2, 9.3, 8.0, 8.7};
    int n = 10;
    print(arr,n);
    return 0;
}
