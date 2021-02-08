#include<iostream>
using namespace std;

int main(){
    int i=0;
    int num[2][3]={ {1,2,3} , {4,5,6} };
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<num[i][j]<<"\n";
        }
    }
    return 0;
}