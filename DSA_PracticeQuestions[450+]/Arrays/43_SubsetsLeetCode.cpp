/* Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    Example 2:
    Input: nums = [0]
    Output: [[],[0]] 

    Visualize the problem using a Recurssion Tree
*/

#include <bits/stdc++.h>
using namespace std;

void subsets2(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
    subs.push_back(sub);
    for (int j = i; j < nums.size(); j++) {
        sub.push_back(nums[j]);
        subsets2(nums, j + 1, sub, subs);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    subsets2(nums, 0, sub, subs);
    return subs;
}

/*  Using Backtracking
    TC : O(N * 2^N)
    SC : O(N)
*/

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int val;
    for(int i=0;i<n;i++){    
        cin >> val;
        nums.push_back(val);
    }

    vector<vector<int>> result = subsets(nums);
    
    for(int i=0;i<result.size();i++){
        for(int num : result[i]){
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*  Iterative Approach :

    Using [1, 2, 3] as an example, the iterative process is like:

    Initially, one empty subset [[]]
    Adding 1 to []: [[], [1]];
    Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
    Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
*/

/*  Bit Manipulation :

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
*/