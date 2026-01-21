#include <iostream>
#include <cmath>
using namespace std;

// Corrected isPrime function
bool isPrime(float num) {
    // Prime numbers must be whole numbers.
    if (floor(num) != num) {
        return false;
    }
    int n = static_cast<int>(num);

    // 0 and 1 are not prime numbers.
    if (n <= 1) {
        return false;
    }
    // 2 is the only even prime number.
    if (n == 2) {
        return true;
    }
    // All other even numbers are not prime.
    if (n % 2 == 0) {
        return false;
    }
    // Check for odd divisors from 3 up to the square root of n.
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Collects all prime numbers from arr into the prime array
void toCollectPrimeNumber(float arr[], int n, float prime[], int& m) {
    m = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            prime[m] = arr[i];
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
    float arr[] = {1, 2, 3, 7, 10, 11.1, 17.3, 23, 32, 41};
    int n = 10;
    int m = 0;
    float prime[10];
    toCollectPrimeNumber(arr, n, prime, m);
    cout << m << " prime numbers in the array: ";
    toPrint(prime, m);
    return 0;
}
