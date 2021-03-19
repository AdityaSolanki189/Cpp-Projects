// Merge Sort is an example of Divide and Conquer Strategy
#include <iostream>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* 
    Time Complexity : 
    Best - Ω(n(logn))
    Avg. - θ(n(logn))
    Worst - O(n(logn)) 
    Worst Case Space Complexity: θ(n) auxiliary
*/

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("\nGiven array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

/* Important Notes :

    • Merging is the process of combining two sorted files to make one bigger sorted file.
    • Selection is the process of dividing a file into two parts: k smallest elements and n – k largest elements.
    • Selection and merging are opposite operations
        ○ selection splits a list into two lists
        ○ merging joins two files to make one file
    • Merge sort is Quick sort’s complement
    • Merge sort accesses the data in a sequential manner
    • This algorithm is used for sorting a linked list• Merge sort is insensitive to the initial order of its input
    • In Quick sort most of the work is done before the recursive calls. Quick sort starts
    with the largest subfile and finishes with the small ones and as a result it needs
    stack. Moreover, this algorithm is not stable. Merge sort divides the list into two
    parts; then each part is conquered individually. Merge sort starts with the small
    subfiles and finishes with the largest one. As a result it doesn’t need stack. This
    algorithm is stable.

    In Merge sort the input list is divided into two parts and these are solved recursively. After
    solving the sub problems, they are merged by scanning the resultant sub problems. Let us assume
    T(n) is the complexity of Merge sort with n elements. The recurrence for the Merge Sort can be
    defined as: 
                Recurrence for MergeSort is T(n) = 2T(n/2) + θ(n).
                Using Master's Theorem, we get, T(n) = θ(nlogn).

*/    