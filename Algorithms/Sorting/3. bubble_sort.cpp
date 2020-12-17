#include <iostream>
using namespace std;
#define MAX 20

void bubble_sort(int arr[], int n){
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

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++) cout<< arr[i] << " ";
    cout<<"\n";
}

/* 
    Time Complexity : 
    Best - Ω(n)
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

    bubble_sort(arr,n);

    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}