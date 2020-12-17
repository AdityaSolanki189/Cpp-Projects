#include<iostream>
using namespace std;

void insertions_sort(int array[],int n){
    int i,key;
    for(int j = 1;j<n;j++){
        key = array[j];
        i = j-1;
        while((i>=0) && (key<array[i])){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}

/* 
    Time Complexity : 
    Best - Ω(n)
    Avg. - θ(n^2)
    Worst - O(n^2) 
*/

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++) cin>>array[i];
    insertions_sort(array,n);
    for(int i=0;i<n;i++) cout<<array[i]<<" ";
}