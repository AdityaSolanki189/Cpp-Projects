#include <iostream>
using namespace std;
#define MAX 20

/* 
    Time Complexity : 
    Best - Ω(n), when flag is used
    Avg. - θ(n^2)
    Worst - O(n^2) 
    Worst case space complexity : O(1) auxiliary
*/

void bubble_sort1(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void bubble_sort2(int arr[], int n){
    int pass, i, temp, swapped=1;
    for(pass=n-1; pass>=0 && swapped; pass--){
        swapped = 0;
        for(i=0; i<=pass-1; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
    }
}


int main(){
    int n;
    cout<<"\nEnter the Number of Elements : ";
    cin>>n;
    if(n>MAX) exit(0);
    int arr[MAX];
    cout<<"\nEnter Elements in the Array : \n";
    for(int i=0;i<n;i++) cin>>arr[i];

    bubble_sort1(arr, n);  // Best Case: O(n^2)

    bubble_sort2(arr, n); // Best Case: O(n)

    printf("\nSorted array is \n");
    for (int i = 0; i < n; i++) cout<< arr[i] << " ";
    cout<<"\n";

    return 0;
}

/* Theory: 
Bubble sort is the simplest sorting algorithm. It works by iterating the input array from the first
element to the last, comparing each pair of elements and swapping them if needed. Bubble sort
continues its iterations until no more swaps are needed. The algorithm gets its name from the way
smaller elements “bubble” to the top of the list. Generally, insertion sort has better performance
than bubble sort. Some researchers suggest that we should not teach bubble sort because of its
simplicity and high time complexity.
The only significant advantage that bubble sort has over other implementations is that it can detect
whether the input list is already sorted or not. */