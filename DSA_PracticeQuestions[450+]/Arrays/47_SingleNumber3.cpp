/*  Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
    You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

    Example 1:
    Input: nums = [1,2,1,3,2,5]
    Output: [3,5]
    Explanation:  [5, 3] is also a valid answer.

    Example 2:
    Input: nums = [-1,0]
    Output: [-1,0]

    Example 3:
    Input: nums = [0,1]
    Output: [1,0]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber3(vector<int>& nums) {
    // Pass 1 : 
    // Get the XOR of the two numbers we need to find
    int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    // Get its last set bit
    diff &= -diff;

    // Pass 2 :
    vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
    for (int num : nums)
    {
        if ((num & diff) == 0) // the bit is not set
        {
            rets[0] ^= num;
        }
        else // the bit is set
        {
            rets[1] ^= num;
        }
    }
    return rets;
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

    vector<int>result = singleNumber3(nums);
    for(int i:result){
        cout << i << " ";
    }

    return 0;
}