#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

bool isSymmetry(char str[]) {
    int i = 0;
    while (i < strlen(str)/2) {
        if (str[i] != str[strlen(str)-1-i]) {
            return false;
        }
        i++;
    }
    return true;
}
int main(){
    char str[10];
    cout << "input a string: ";
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // removing end line
    if (isSymmetry(str)) {
        cout << "Symmetry String" << endl;
        } 
        else {
        cout << "Not Symmetry String" << endl;
    }
    return 0;
}