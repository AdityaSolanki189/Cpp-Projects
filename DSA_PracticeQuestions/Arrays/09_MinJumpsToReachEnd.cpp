/* 
Minimum number of jumps
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element. */

/* Approach: Dynamic Programming

~ In this way, make a jumps[] array from left to right such that   jumps[i] indicate the minimum number of jumps needed to reach arr[i] from arr[0].

~ To fill the jumps array run a nested loop inner loop counter is j and outer loop count is i.

~ Outer loop from 1 to n-1 and inner loop from 0 to n-1.

~ if i is less than j + arr[j] then set jumps[i] to minimum of jumps[i] and jumps[j] + 1. initially set jump[i] to INT MAX

~ Finally, return jumps[n-1]. 
*/

#include<bits/stdc++.h>
using namespace std;

int getMinJumps(int array[], int n){
    int* jumps = new int[n];
    int i, j;
 
    if (n == 0 || array[0] == 0)
        return 0;

    jumps[0] = 0;
 
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + array[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];
   
    cout << "Minimum Number Of Jumps to reach the End : " << getMinJumps(array, n);

    return 0;
}

/* 
Naive Recursive Approach

int getMinJumps(int array[], int n){
    
    if(n==0 || n==1)
        return 0;
    int res = INT_MAX;
    
    for (int i = n - 2; i >= 0; i--) {
        if (i + array[i] >= n - 1) {
            int sub_res = getMinJumps(array, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }

    return res;
} */
