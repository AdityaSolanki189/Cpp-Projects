/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory. 

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
*/

/* Can be solved using STL function: next_permutation(v.begin(),v.end()); */

#include <bits/stdc++.h>
using namespace std;

void next_permutation(vector<int>& nums){
    bool flag = false;
    int i;
    for(i=nums.size()-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            flag = true;
            break;
        }
    }
    
    if(flag){
        for(int j=nums.size()-1; j>i; j--){
            if(nums[i] < nums[j]){
                swap(nums[i],nums[j]);
                break;
            }
        }
    }
    else{    
        i=0;
    }
    reverse(nums.begin()+i+1, nums.end());
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

    next_permutation(nums);

    //cout << "Next Permutation : " ;
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }

    return 0;
}