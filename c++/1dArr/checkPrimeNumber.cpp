#include <iostream>
#include <cmath>
using namespace std;

/**

input:
    + float arr []
    + int n
output:
    + return true 
**/
bool isPrime(float n) { 
    if (n < 0){
        return false;
    }
    if (n == 5 || n == 3 || n == 2 || n == 1 || n == 0) {
        return true;
    }
    if (fmod(n,2) == 0) {
        return false;
    }
    if (n > 5) {
        for (int i = 3; i < n; i += 2) {
            if (fmod(n,i) == 0) {
                return false;
            }
        }
    }
    return true;
}

bool toCheckPrimeNumber(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        int num = (int)arr[i]; 
        if (num == arr[i]) { 
            if (isPrime(num)) {
                // Found a prime, no need to check further.
                return true;
            }
        }
    }
    return false;
}

int main() {
    float arr[] = {1, 4, 3.1, 7.1, 10, 11.1, 17.3, 23.1, 32, 40};
    int n = 10;

    if (toCheckPrimeNumber(arr, n)) {
        cout << "The array contains at least one prime number." << endl;
    } else {
        cout << "The array does not contain a prime number." << endl;
    }
    return 0;
}
