#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void printString(char str[]) {
    cout << " + print by cout: " << str << endl;
    printf(" + print by printf: %s\n",str); 
    printf(" + print by put: "); 
    puts(str); 

}
int main(){
    char str[50]; 
    cout << "input a string: ";
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = 0; // Requires <cstring>
    cout << "Expetect Output:" << endl;
    printString(str);
    return 0;
}