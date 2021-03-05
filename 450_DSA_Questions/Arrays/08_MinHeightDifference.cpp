/* 
Minimize the maximum difference between the heights
The idea is to sort all elements increasing order. And for all elements check if subtract(element-k) and add(element+k) makes any changes or not. */

#include <bits/stdc++.h>
using namespace std;

int getMinDif(int arr[], int n, int k){
    if (n == 1) 
        return 0; 

    sort(arr, arr+n); 
  
    int ans = arr[n-1] - arr[0]; 
  
    // Handle corner elements 
    int small = arr[0] + k; 
    int big = arr[n-1] - k; 
    if (small > big) 
        swap(small, big); 
  
    // Traverse middle elements 
    for (int i = 1; i < n-1; i ++) { 
        int subtract = arr[i] - k; 
        int add = arr[i] + k; 
  
        // If both subtraction and addition 
        // do not change diff 
        if (subtract >= small || add <= big) 
            continue; 
  
        // Either subtraction causes a smaller 
        // number or addition causes a greater 
        // number. Update small or big using 
        // greedy approach (If big - subtract 
        // causes smaller diff, update small 
        // Else update big) 
        if (big - subtract <= add - small) 
            small = subtract; 
        else
            big = add;
    }
    return min(ans, big-small);
}

int main(){
    int n, k;
    cin >> n >> k;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];

    cout << "The Minimum Difference : " << getMinDif(array, n, k) << "\n";

    return 0;
}