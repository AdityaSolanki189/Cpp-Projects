#include <iostream>
using namespace std;
#define MAX 20

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int indexof_smallest = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[indexof_smallest]){
                indexof_smallest = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexof_smallest];
        arr[indexof_smallest] = temp;
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++) cout<< arr[i] << " ";
    cout<<"\n";
}

/* 
    Time Complexity : 
    Best - Ω(n^2)
    Avg. - θ(n^2)
    Worst - O(n^2) 
    Worst case space complexity: O(1) auxiliary
*/

int main(){
    int n;
    cout<<"\nEnter the Number of Elements : ";
    cin>>n;
    if(n>MAX) exit(0);
    int arr[MAX];
    cout<<"\nEnter Elements in the Array : \n";
    for(int i=0;i<n;i++) cin>>arr[i];

    selection_sort(arr,n);

    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}

/* Theory:
Selection sort is an in-place sorting algorithm. Selection sort works well for small files. It is used
for sorting the files with very large values and small keys. This is because selection is made
based on keys and swaps are made only when required.
Advantages
    • Easy to implement
    • In-place sort (requires no additional storage space)
Disadvantages
    • Doesn’t scale well: O(n^2)
Algorithm
    1. Find the minimum value in the list
    2. Swap it with the value in the current position
    3. Repeat this process for all the elements until the entire array is sorted
This algorithm is called selection sort since it repeatedly selects the smallest element. */
