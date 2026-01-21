#include <iostream>
using namespace std;

/* 
input:
 + float a[]
 + int n
 + int element
Ouput:
 + return int count
*/

float countElement(float a[], int n, int element, int& count){
    for(int i = 0; i < n; i++){
        if (a[i] == element){
            count++;
        }
    }
    return count;
}

int main(){
    int count = 0;
    float initArr[] = {1, 1.1, 2, 2.2, 3, 4, 2, 1, 3, 4, 3, 4, 1, 4, 3};
    int n = 15;
    int element = 4;
    countElement(initArr, n, element, count);
    cout << "There are " << count << " of number " << element << endl;
    return 0;
}