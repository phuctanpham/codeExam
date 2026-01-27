#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

void reverseString(char str[]) {
    int i = 0;
    while (i <  (strlen(str) / 2)) {
        str[i] = str[i] ^ str[strlen(str)-1-i]; // Bước 1: a ^ b 
        str[strlen(str)-1-i]   = str[i] ^ str[strlen(str)-1-i]; // Bước 2: (a ^ b ) ^ b => a
        str[i] = str[i] ^ str[strlen(str)-1-i]; // Bước 3: (a ^ b) ((a ^ b ) ^ b ) => b
        i++;
    }
}
int main(){
    char str[10];
    cout << "input a string: ";
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // removing end line
    reverseString(str);
    cout << "Reverse String: " << str << endl;
    return 0;
}