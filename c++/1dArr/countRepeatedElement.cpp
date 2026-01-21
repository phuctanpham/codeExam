#include <iostream>
using namespace std;
float newArr[10];
int m = 0;
// Checks if a value already exists in the simplified array
bool toDuplicate(float arr[], int n, float checkValue) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == checkValue) {
            return true;
        }
    }
    return false;
}
// Fills newArr with unique elements from arr
void simplifyArr(float arr[], int n, int& m) {
    for(int i = 0; i < n; i++) {
        if(!(toDuplicate(newArr, m, arr[i]))) {
            newArr[m] = arr[i];
            m++;
        }
    }
}
// Counts how many times an element appears in the original array
int countElement(float arr[], int n, float element) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

// Print result
int main() {
    float Arr[] = {1, 1.1, 2, 2.2, 3, 4, 2, 1, 3, 4, 3, 4, 1, 4, 3};
    int n = 15;
    simplifyArr(Arr, n, m);
    for(int i = 0; i < m; i++) {
        float element = newArr[i];
        int count = countElement(Arr, n, element);
        cout << i + 1 << ") There are " << count << " of number " << element << endl;
    }

    return 0;
}