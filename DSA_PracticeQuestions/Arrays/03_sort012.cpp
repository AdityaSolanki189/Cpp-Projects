/* Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo */
/* Simplest Solution 
Count the number of 0’s, 1’s and 2’s. After Counting, put all 0’s first, then 1’s and lastly 2’s in the array. 
 */

//3-Way partition method:
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], int N){
    int low = 0; 
    int hi = N - 1; 
    int mid = 0; 
  
    while (mid <= hi) { 
        switch (array[mid]) { 
            case 0: 
                swap(&array[low++], &array[mid++]); 
                break; 
  
            case 1: 
                mid++; 
                break; 
  
            case 2:    
                swap(&array[mid], &array[hi--]); 
                break; 
        } 
    }
}

int main(){
    int array[6];
    for(int i=0;i<6;i++) cin>>array[i]; 
    sort(array,6);

    cout << "Sorted Array : ";
    for(int i=0;i<6;i++) cout << array[i] << " ";

    return 0;
}

