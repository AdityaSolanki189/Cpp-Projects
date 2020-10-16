#include<iostream>
#include<string>
using namespace std;

int main(){
    int a,b,c;
    string str;
    cout<<"Heellooo Woorlldd!\n";
    cin>>a>>b;
    cout<<"Enter Your String : "<<endl;
    cin.ignore();
    getline(cin,str);
    c = a+b;
    cout<<c<<str;
    return 0;
}