/* Intersection of Two Arrays II
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted. */

#include<bits/stdc++.h>
using namespace std;

// Hash table solution:
// Time: O(m + n) Space: O(m + n)
vector<int> Intersection1(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> dict;
    vector<int> res;
    for(int i = 0; i < (int)nums1.size(); i++){ 
        dict[nums1[i]]++;
    }
    for(int i = 0; i < (int)nums2.size(); i++){
        if(--dict[nums2[i]] >= 0){ 
            res.push_back(nums2[i]);
        }
    }
    return res;
}

// Hash table solution2:
// Time: O(m + n) Space: O(m)
vector<int> Intersection2(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> dict;
    vector<int> res;
    for(int i = 0; i < (int)nums1.size(); i++) {
        dict[nums1[i]]++;
    }    

    for(int i = 0; i < (int)nums2.size(); i++){
        if(dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0){
            res.push_back(nums2[i]);
        }    
    }        
    return res;
}

// Sort and two pointers Solution:
// Time: O(max(m, n) log(max(m, n))) Space: O(m + n)
vector<int> Intersection3(vector<int>& nums1, vector<int>& nums2){
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int n1 = (int)nums1.size(), n2 = (int)nums2.size();
    int i1 = 0, i2 = 0;
    
    vector<int> res;
    
    while(i1 < n1 && i2 < n2){
        if(nums1[i1] == nums2[i2]) {
            res.push_back(nums1[i1]);
            i1++;
            i2++;
        }
        else if(nums1[i1] > nums2[i2]){
            i2++;
        }
        else{
            i1++;
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