#include <bits/stdc++.h> 
using namespace std;  
  
void swap(int* a, int* b){  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

/* 
int partition (int arr[], int low, int high){  
    int left, right, pivot_item = arr[low];
    left = high;
    while(left < right){
        // Move left while item < pivot
        whlie(arr[left] <= pivot_item)
            left++;
        
        // Move right while item > pivot
        while(arr[right] > pivot_item)
            right--;
        
        if(left < right)
            swap(arr, left, right);
    }
    // right is final positoion for the pivot
    arr[low] = arr[right];
    arr[right] = pivot_item;
    return right;
}   */
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high){  
    if (low < high){  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pivot = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pivot - 1);  
        quickSort(arr, pivot + 1, high);  
    }  
}  

void printArray(int arr[], int size){  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
/* 
    Time Complexity : 
    Best - Ω(n(logn))
    Avg. - θ(n(logn))
    Worst - O(n^2) 
    Worst case space complexity : O(1)
*/

int main(){  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  

/* Theory:
Quick sort is an example of a divide-and-conquer algorithmic technique. It is also called
partition exchange sort. It uses recursive calls for sorting the elements, and it is one of the
famous algorithms among comparison-based sorting algorithms.
    Divide: The array A[low ...high] is partitioned into two non-empty sub arrays A[low ...q] and A[q + 1... high], such that each element of A[low ... high] is less than or equal to each element of A[q + 1... high]. The index q is computed as part of this partitioning procedure.
    
    Conquer: The two sub arrays A[low ...q] and A[q + 1 ...high] are sorted by recursive calls to
    Quick sort.
Algorithm
The recursive algorithm consists of four steps:
    1) If there are one or no elements in the array to be sorted, return.
    2) Pick an element in the array to serve as the “pivot” point. (Usually the left-most
    element in the array is used.)
    3) Split the array into two parts – one with elements larger than the pivot and the other
    with elements smaller than the pivot.
    4) Recursively repeat the algorithm for both halves of the original array.
*/