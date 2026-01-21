#include <iostream>
#include <cmath>
using namespace std;

// Corrected isPrime function
bool isSquare(float n) {
    float r = int(sqrt(n));
    if (r * r == n){
        return true;
    }
    return false;
}

// Collects all square numbers from arr into the prime array
void toCollectSquareNumber(float arr[], int n, float square[], int& m) {
    m = 0;
    for (int i = 0; i < n; i++) {
        if (isSquare(arr[i])) {
            square[m] = arr[i];
            m++;
        }
    }
}

// Prints the elements of a float array
void toPrint(float arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    float arr[] = {1, 4, 3, 7, 16, 11.1, 17.3, 144, 32, 41};
    int n = 10;
    int m = 0;
    float prime[10];
    toCollectSquareNumber(arr, n, prime, m);
    cout << m << " square numbers in the array: ";
    toPrint(prime, m);
    return 0;
}
