#include<iostream>
#include<string>
using namespace std;

int longest_rep(string str){
    int count = 1;
    int output = 0;
    int j =0;
    for(int i=0;i<str.length()-1;i++){
        j=i;
        while(i<(str.length()-1) && str[i] == str[i+1]){
            i++;
            count++;
        }
        if(count>output){
            output = j;
        }
        count = 1;
    }
    return output;
}

int main(){
    string str;
    getline(cin,str);

    cout<<longest_rep(str);
    
    return 0;
}