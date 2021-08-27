/*  Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:
    Input: nums = [2,2,1]
    Output: 1
    
    Example 2:
    Input: nums = [4,1,2,1,2]
    Output: 4 

    Basic approach would be to use the hash map and count the freq\
*/

#include <bits/stdc++.h>
using namespace std;

/*  Simple use of XOR
    0 ^ 2 = 2
    2 ^ 2 = 0
    0 ^ 1 = 1

    1 ^ 8 = 9
    8 ^ 9 = 1
    9 ^ 1 = 8
*/    
int singleNumber(vector<int>& nums) {
    int number = 0;
    for(int i=0;i<nums.size();i++){
        number ^= nums[i];
    }
    return number;
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