//Improvised version of Insertion Sort. Using Repetition of Insertion Sort.
#include  <iostream> 
using namespace std; 
  
void shellSort(int arr[], int n) { 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) {
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; 
            }
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        }
    }
}
  
void printArray(int arr[], int n) { 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
} 

/*  Time Complexity:
    Worst case complexity depends on gap sequence. 
    Best Known Worst Case : O(n(log^2)n)    
    Best Case Complexity : O(n)
    Average Case complexity depends on gap sequence.
    Worst case space complexity : O(n)
*/

int main() 
{ 
    int arr[] = {12, 34, 54, 2, 3}, i; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Array before sorting: \n"; 
    printArray(arr, n); 
  
    shellSort(arr, n); 
  
    cout << "\nArray after sorting: \n"; 
    printArray(arr, n); 
  
    return 0; 
} 

/* Theory:
Shellsort works by starting with big enough (but not larger than the array size) h so as to allow
eligible element exchanges that are far apart. Once a sort is complete with a particular h, the
array can be said as h-sorted. The next step is to reduce h by a certain sequence, and again
perform another complete h-sort. Once h is 1 and h-sorted, the array is completely sorted. Notice
that the last sequence for ft is 1 so the last sort is always an insertion sort, except by this time the
array is already well-formed and easier to sort.

Shell sort uses a sequence h1,h2, ...,ht called the increment sequence. Any increment sequence is
fine as long as h1 = 1, and some choices are better than others. Shell sort makes multiple passes
through the input list and sorts a number of equally sized sets using the insertion sort. Shell sort
improves the efficiency of insertion sort by quickly shifting values to their destination.
Shell sort is efficient for medium size lists. For bigger lists, the algorithm is not the best choice. It
is the fastest of all O(n^2) sorting algorithms.

The disadvantage of Shell sort is that it is a complex algorithm and not nearly as efficient as the
merge, heap, and quick sorts. Shell sort is significantly slower than the merge, heap, and quick
sorts, but is a relatively simple algorithm, which makes it a good choice for sorting lists of less
than 5000 items unless speed is important. It is also a good choice for repetitive sorting of
smaller lists.

The best case in Shell sort is when the array is already sorted in the right order. The number of
comparisons is less. The running time of Shell sort depends on the choice of increment sequence.
*/