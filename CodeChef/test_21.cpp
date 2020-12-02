#include <iostream>
using namespace std;

void SWAP(char list[], int i, int j){
    char t=list[i];
    list[i]=list[j];
    list[j]=t;
}

void func(char list[], int i, int n){
    int j, temp;
    if(i==n){
        for(j=0; j<=n; j++){
            cout<<list[j];
        }
        cout<<" ";
    }
    else{
        for(j=i; j<=n; j++){
            SWAP(list, i, j);
            func(list, i+1, n);
            SWAP(list, i, j);
        }
    }
}

int main(){

    char list[3] = {'a','b','c'};
    int i=0;
    int n=2;
    func(list,i,n);

    return 0;
}