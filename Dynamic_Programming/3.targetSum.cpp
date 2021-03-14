/* 
Write a function 'canSum(targetSum, numbres' that takes in a targetSum and an array of numbers as argument.
The function should return a boolean indicating whether or not it is possible to generate the targetSum using numbers from the array. 
You may use an element of the array as many times as needed. 
You may assume that all input numbers are non-negative.
*/

#include<bits/stdc++.h>
using namespace std;

// Naive way Brute force (Takes time for larger values)
string canSum1(int nums[], int n, int target){ 
    if(target == 0) return "True";
    if(target < 0) return "False";

    for(int i=0;i<n;i++){
        int remainder = target - nums[i];
        if(canSum1(nums, n, remainder) == "1")
            return "True";
    }
    return "False";
}

bool dp[1005];

// Memoized Efficient way
bool canSum2(int nums[], int n, int target){ 
    if(target == 0) return true;
    if(target < 0) return false;

    if(dp[target] != false) return dp[target];

    for(int i=0;i<n;i++){
        int remainder = target - nums[i];
        if(canSum1(nums, n, remainder) == true){
            dp[target] = true;
            return true;
        }
    }
    dp[target] = false;
    return false;
}

int main(){
    int n, target;
    cin >> n >> target;
    int nums[n];
    for(int i=0;i<n;i++) cin >> nums[i];

    //cout << canSum1(nums, n, target) << "\n";

    cout << canSum2(nums, n, target) << "\n";
    /* if(canSum2(nums, n, target) == 1)
        cout << "True" << "\n";
    else 
        cout << "False" << "\n"; */
    
    return 0;
}