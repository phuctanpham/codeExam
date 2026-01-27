#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

int countSpecial(char str[]) {
    int i = 0;
    int m= 0;
    while (str[i] != '\0') {
        if ( ! ( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') && str[i] == ' ' ) ) {
            m++;
        }
        i++;
    }
    return m;
}
int main(){
    char str[10];
    cout << "input a string: ";
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // removing end line
    int m = countSpecial(str);
    if (m > 0) {
        cout << "Special Character in String: " << m << endl;
        } 
        else {
        cout << "Not Special Character in String" << endl;
    }
    return 0;
}