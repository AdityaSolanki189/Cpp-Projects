/* An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers. Order doesnot matter after rearranging. */

#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange(int array[], int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(array[i] < 0){
            if(i != j){
                swap(array[i],array[j]);
            }
            j++;
        }
    }
}

int main(){
    int array[6];
    for(int i=0;i<6;i++) cin >> array[i];
    
    rearrange(array,6);
    cout << "After Re-arranging we get : \n";
    
    for(int i=0;i<6;i++) cout << array[i] << " ";

    return 0;
}