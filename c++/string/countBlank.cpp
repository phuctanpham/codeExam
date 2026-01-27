#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int countBlank(char str[]) {
    int i = 0;
    int m = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            m++;
        }
        i++;
    }
    return m;
}
int main(){
    char str[50]; 
    cout << "input a string: ";
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = 0; // Requires <cstring>
    cout << "Total Blanks: " << countBlank(str) << endl;
    return 0;
}