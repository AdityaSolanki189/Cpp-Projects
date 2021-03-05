#include <iostream>
#include <algorithm>
using namespace std;

int kth_largest(int array[], int n, int k){
    sort(array, array+n, greater<int>());
    return array[k-1];
}

int Kth_smallest(int array[], int n, int k){
    sort(array, array+n);
    return array[k-1];
}

int main(){

    int array[6];
    for(int i=0;i<6;i++) cin >> array[i];
    int k;
    cout << "Enter value of K : ";
    cin >> k;

    cout << "The Kth Largest Element is : " << kth_largest(array,6,k);

    cout << "\nThe Kth Smallest Element is : " << Kth_smallest(array,6,k);
    return 0;
}


/* Quick Select: 
This is an optimization over method 1 if QuickSort is used as a sorting algorithm in first step. In QuickSort, we pick a pivot element, then move the pivot element to its correct position and partition the array around it. The idea is, not to do complete quicksort, but stop at the point where pivot itself is k’th smallest element. Also, not to recur for both left and right sides of pivot, but recur for one of them according to the position of pivot. The worst case time complexity of this method is O(n2), but it works in O(n) on average.  

    #include <climits>
    #include <iostream>
    using namespace std;
 
    int partition(int arr[], int l, int r);
 
// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT

    int kthSmallest(int arr[], int l, int r, int k){
    
    // If k is smaller than number of elements in array
        if (k > 0 && k <= r - l + 1) {
        // Partition the array around last element and get
        // position of pivot element in sorted array
            int pos = partition(arr, l, r);
 
        // If position is same as k
            if (pos - l == k - 1)
                return arr[pos];
            if (pos - l > k - 1) // If position is more, recur for left subarray
                return kthSmallest(arr, l, pos - 1, k);
 
        // Else recur for right subarray
            return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
        }
 
    // If k is more than number of elements in array
        return INT_MAX;
    }
 
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
 
// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right

    int partition(int arr[], int l, int r){
        int x = arr[r], i = l;
        for (int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[r]);
        return i;
    }

*/
