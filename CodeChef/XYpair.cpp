#include <iostream>
#include <String.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int len = str.length();
        int pair =0;
        for(int i=0;i<len;i++){
            if((str.at(i)=='x'&& str.at(i+1)=='y') || (str.at(i)=='y'&& str.at(i+1)=='x')){
                i++;
                pair++;
                continue;
            }
        }
    }
    return 0;
}
