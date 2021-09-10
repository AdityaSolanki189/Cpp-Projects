/*  Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    Example 2:
    Input: nums = [0]
    Output: [[],[0]]

    Visualize the problem using a Recurssion Tree
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > totalset = {{}};
    sort(S.begin(),S.end());
    for(int i=0; i<S.size();){
        int count = 0; // num of elements are the same
        while(count + i<S.size() && S[count+i]==S[i])  count++;
        int previousN = totalset.size();
        for(int k=0; k<previousN; k++){
            vector<int> instance = totalset[k];
            for(int j=0; j<count; j++){
                instance.push_back(S[i]);
                totalset.push_back(instance);
            }
        }
        i += count;
    }
    return totalset;
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

    vector<vector<int>> result = subsetsWithDup(nums);
    
    for(int i=0;i<result.size();i++){
        for(int num : result[i]){
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
