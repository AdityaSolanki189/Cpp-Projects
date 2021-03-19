#include<iostream>
using namespace std;

void insertions_sort(int array[],int n){
    int i,key;
    for(int j = 1;j<n;j++){
        key = array[j];
        i = j-1;
        while((i>=0) && (key<array[i])){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}

/* 
    Time Complexity : 
    Best - Ω(n) |  θ(n)
    Avg. - θ(n^2)
    Worst - O(n^2)  | θ(n^2)
    Worst case space complexity: O(n^2) total, O(1) auxiliary
*/

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++) cin>>array[i];
    insertions_sort(array,n);
    for(int i=0;i<n;i++) cout<<array[i]<<" ";
    return 0;
}

/* Theory:
Insertion sort is a simple and efficient comparison sort. In this algorithm, each iteration removes
an element from the input data and inserts it into the correct position in the list being sorted. The
choice of the element being removed from the input is random and this process is repeated until
all input elements have gone through.
Advantages
    • Simple implementation
    • Efficient for small data
    • Adaptive: If the input list is presorted [may not be completely] then insertions sort takes O(n + d), where d is the number of inversions
    • Practically more efficient than selection and bubble sorts, even though all of them have O(n^2) worst case complexity• Stable: Maintains relative order of input data if the keys are same
    • In-place: It requires only a constant amount O(1) of additional memory space
    • Online: Insertion sort can sort the list as it receives it 
Algorithm
Every repetition of insertion sort removes an element from the input data, and inserts it into the correct position in the already-sorted list until no input elements remain. Sorting is typically done in-place. The resulting array after k iterations has the property where the first k + 1 entries are
sorted.
Each element greater than x is copied to the right as it is compared against x.
*/ 
