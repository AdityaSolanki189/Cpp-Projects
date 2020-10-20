#include<iostream>
#include<string>
using namespace std;

int longest_rep(string str){
    int count = 1;
    int longest = 0;
    for(int i=0;i<str.length()-1;i++){
        if(str[i] == str[i+1]){
            count++;
        }
        else{
            longest = max(longest,count);
            count = 1;
        }
    }
    longest = max(longest,count);
    return longest;
}

int main(){
    string str;
    getline(cin,str);

    cout<<longest_rep(str);
    
    return 0;
}