#include <iostream>
#include <math.h>
using namespace std;

void sort(int array[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j+1<n-i;j++){
            if(array[j]>array[j+1]){
             int temp=array[j];
             array[j]=array[j+1];
             array[j+1]=temp;
            } 
        }
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int array[n];
        for(int i=0;i<n;i++) cin>>array[i];
        sort(array,n);
        for(int i=0;i<n;i++) cout<<array[i]<<" ";
        cout<<endl;
        int a=0,b=0;
        for(int i=0;i<n-1;i++){
            if(array[i] != 0){
                if(abs(array[i]-array[i+1]) <= 1 ){
                    array[i] = 0;
                    sort(array,n);
                }
            }
            for(int i=0;i<n;i++) cout<<array[i]<<" ";
            cout<<endl;
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(array[i]>0) count++;
        }
        if(count != 1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}