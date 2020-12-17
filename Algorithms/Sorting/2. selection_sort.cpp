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