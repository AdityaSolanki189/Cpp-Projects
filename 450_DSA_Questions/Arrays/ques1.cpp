#include <iostream>
using namespace std;

void reverse(int array[],int start,int end){
    while(start<end){
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }    
}

//using reccursive method
void rec_reverse(int array[],int start,int end){
    if (start >= end){
        return;
    }
    int temp = array[start]; 
    array[start] = array[end];
    array[end] = temp;
     
    // Recursive Function calling
    rec_reverse(array, start + 1, end - 1);
}

void print(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++) cin>>array[i];
    int start = 0,end = n-1;
    reverse(array,start,end);
    //rec_reverse(array,start,end);
    print(array,n);
    return 0;
}