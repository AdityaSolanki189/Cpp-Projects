/* Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted. */

#include<bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int>& nums1, vector<int>& nums2){
    if(nums1.empty() || nums2.empty())
        return vector<int>();

    unordered_set<int> set(nums1.begin(), nums1.end());

    vector<int> res;
    for(auto a : nums2){
        if (set.erase(a) > 0){ // if n exists in set, then 1 is returned and n is erased; otherwise, 0.
            res.push_back(a);
        } 
    }

    return res;
}

int main(){
    int n,x,m;
    cin >> n >> m;
    vector<int> nums1;
    for(int i=0;i<n;i++) {
        cin >> x;
        nums1.push_back(x);
    }
    
    vector<int> nums2;
    for(int i=0;i<m;i++) {
        cin >> x;
        nums2.push_back(x);
    }

    vector<int> res = Intersection(nums1, nums2);

    for(int i=0;i<res.size();i++){
        cout << res[i] << "\n";
    }

    return 0;
}