#include<iostream>
using namespace std;

int f(int x, int c){
    c = c-1;
    if(c==0) return 1;
    x = x+1;
    return f(x,c)*x;
}

int main(){
    int n = 5;
    cout  << f(n,5) << "\n";
    return 0;
}