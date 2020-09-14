#include <iostream>
using namespace std;

void sort(int array[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j+1<n-i;j++){
            if(array[j]<array[j+1]){
             int temp=array[j];
             array[j]=array[j+1];
             array[j+1]=temp;
            } 
        }
    }
}
//highest stick -> second Heighest stick -> third heighest stick -> so no... till we reach height = 0
//Number of Operations is Equal to Number Of Unique heights
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int heights[n];
        for(int i=0;i<n;i++) cin>>heights[i];
        sort(heights,n);
        
        for(int i=0;i<n;i++) cout<<heights[i]<<" ";
    }
    return 0;
}