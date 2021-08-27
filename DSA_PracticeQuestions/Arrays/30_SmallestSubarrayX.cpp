/* Smallest subarray with sum greater than x 
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.
Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:
Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6} */

#include<bits/stdc++.h>
using namespace std;

// Sliding Window Approach (important)
void getSubarray(int array[], int n, int x){
    int right, left=0, sum=0;
    int mn = 32000;

    for(right=0;right<n;right++){
        sum += array[right];
        while (sum > x){
            mn = min(mn, right-left+1);
            sum -= array[left];
            left++;
        }
    }
    cout << mn << "\n";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;
        int array[n], i;

        for(i=0;i<n;i++) cin >> array[i];

        getSubarray(array, n, x);
    }
    return 0;
}
