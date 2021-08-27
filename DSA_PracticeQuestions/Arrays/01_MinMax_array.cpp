/* How do we return multiple values from a C function? We can do it either using structures or pointers. 
We have created a structure named pair (which contains min and max) to return multiple values.
 */
#include <iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair getMinMax(int array[], int n){
    struct Pair minmax;
    
    if (n == 1){
        minmax.max = array[0];
        minmax.min = array[0];     
        return minmax;
    } 
  
    if (array[0] > array[1]){
        minmax.max = array[0];
        minmax.min = array[1];
    } 
    else{
        minmax.max = array[1];
        minmax.min = array[0];
    } 
     
    for(int i = 2; i < n; i++){
        if (array[i] > minmax.max)     
            minmax.max = array[i];
             
        else if (array[i] < minmax.min)     
            minmax.min = array[i];
    }
    return minmax;
}

int main(){

    int array[6];
    for(int i=0;i<6;i++){
        cin >> array[i];
    }
    struct Pair minmax = getMinMax(array, 6);
    cout << "Minimum Element : " << minmax.min << "\n";
    cout << "Maximum Element : " << minmax.max << "\n";

    return 0;
}

/* Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array. (Tournament Method) 

    struct Pair getMinMax(int arr[], int low, int high){
    struct Pair minmax, mml, mmr;     
    int mid;
     
    // If there is only one element 
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];     
        return minmax;
    } 
     
    // If there are two elements 
    if (high == low + 1) { 
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } 
        else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        } 
        return minmax;
    }
     
    // If there are more than 2 elements 
    mid = (low + high) / 2; 
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high); 
     
    // Compare minimums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;     
     
    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;     
     
    return minmax;

*/

/* Compare Method:- 
If n is odd then initialize min and max as first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively.  

    struct Pair getMinMax(int arr[], int n) { 
    struct Pair minmax;     
    int i; 
     
    // If array has even number of elements 
    // then initialize the first two elements 
    // as minimum and maximum 
    if (n % 2 == 0) { 
        if (arr[0] > arr[1]) { 
            minmax.max = arr[0]; 
            minmax.min = arr[1]; 
        } 
        else { 
            minmax.min = arr[0]; 
            minmax.max = arr[1]; 
        } 
         
        // Set the starting index for loop 
        i = 2; 
    } 
     
    // If array has odd number of elements 
    // then initialize the first element as 
    // minimum and maximum 
    else { 
        minmax.min = arr[0]; 
        minmax.max = arr[0]; 
         
        // Set the starting index for loop 
        i = 1; 
    } 
     
    // In the while loop, pick elements in 
    // pair and compare the pair with max 
    // and min so far 
    while (i < n - 1) {         
        if (arr[i] > arr[i + 1]) { 
            if(arr[i] > minmax.max)     
                minmax.max = arr[i]; 
                 
            if(arr[i + 1] < minmax.min)         
                minmax.min = arr[i + 1];     
        } 
        else { 
            if (arr[i + 1] > minmax.max)     
                minmax.max = arr[i + 1]; 
                 
            if (arr[i] < minmax.min)         
                minmax.min = arr[i];     
        } 
         
        // Increment the index by 2 as 
        // two elements are processed in loop 
        i += 2; 
    }         
    return minmax; 

*/