/* Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
 
Constraints:
1 <= nums.legth <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique. */

#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(nlog(n-k))
vector<int> topK_freq(vector<int>& nums, int k){
    unordered_map<int,int> map;
    for(int num : nums){
        map[num]++;
    }
    
    vector<int> res;
    // pair<first, second>: first is frequency,  second is number
    priority_queue<pair<int,int>> pq; 
    for(auto it = map.begin(); it != map.end(); it++){
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > (int)map.size() - k){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}

int main(){
    int n,x,k;
    cin >> n >> k;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        cin >> x;
        nums.push_back(x);
    }
    
    vector<int> res = topK_freq(nums, k);

    for(int i=0;i<res.size();i++){
        cout << res[i] << "\n";
    }
    return 0;
}