/*  Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:
    Input: nums = [2,2,3,2]
    Output: 3

    Example 2:
    Input: nums = [0,1,0,1,0,1,99]
    Output: 99

    1. HashMap + LinearTraversal O(NlogN) | O(N)
    2. Sorting + LinearTraversal O(NlogN + N)
        Start at location i=1, check if i-1 == i, if yes then continue else return i-1. 
        Continue, move 3 steps ahead and repeat the above steps. 
        This can also be reffered to as checking in clusters
        Corner Case :
        i.  the single number is at position 0, check if num[0] == num[1]
        ii. the single number is at position (n-1), check is num[n-1] == num[n-2].
    3. Coutning Set Bits
        Since the numbers repeat thrice, we will sum up the last bits of each nums binary rep. and MOD it by 3.
        After completing this we will shift to the next bit, (Shift = 2) and do the same process
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    //Using XOR + AND combination
    int ones = 0;
    int twos = 0;
    for(auto ele: nums){
        ones = (ones^ele) & (~twos);
        twos = (twos^ele) & (~ones);
    }
    return ones;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int val;
    for(int i=0;i<n;i++){    
        cin >> val;
        nums.push_back(val);
    }

    cout << singleNumber(nums);

    return 0;
}