//Given an array (or string), the task is to reverse the array/string.

#include <iostream>
using namespace std;

void reverse_array(int array[],int start, int end){
    if(start>=end) return;

    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;

    reverse_array(array,start+1,end-1);
}

void print_array(int array[], int size){
    for(int i=0;i<size;i++){
        cout << array[i] << " ";
    }
}

int main(){
    
    int array[6];
    for(int i=0;i<6;i++) cin>>array[i];
    
    reverse_array(array,0,5);

    cout<<"Reversed Array : "<<"\n";
    print_array(array,6);
    return 0;
}