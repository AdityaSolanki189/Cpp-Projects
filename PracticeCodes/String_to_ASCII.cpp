#include <iostream>
using namespace std;

int main(){
    char str[100];
    int i=0;
    printf("\nEnter any string to get ASCII Value:\n");
    scanf("%s",str);
    printf("\nASCII values of each characters of given string:\n");
    int str_ascii = 0;
    while(str[i]){
        str_ascii += str[i];
        printf("%d ",str[i++]);
    }
    cout << "\n" << str_ascii;
    int hf = str_ascii % 13;
    cout << "\nHF : " << hf;
    return 0;
}