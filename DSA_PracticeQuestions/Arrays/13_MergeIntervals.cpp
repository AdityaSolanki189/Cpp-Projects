/* 
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6]. */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& v){
    vector<vector<int>> res;
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();++i){
        if(res.size() == 0 || v[i][0] > res.back()[1])
            res.push_back(v[i]);
        else 
            res.back()[1] = max(res.back()[1], v[i][1]);
    }
    return res;
}

/*  vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        int index = 0;
        vector<vector<int>> ans;
        ans.push_back(intervals[index]);
        for(int i = 1; i < intervals.size(); i++){
             if(ans[index][1] >= intervals[i][0])
                 ans[index][1] = max(ans[index][1], intervals[i][1]);
            else{
                ans.push_back(intervals[i]);
                index++;
            }
            
        }
        return ans;
    } 
*/

int main(){
    int n; //Total Number of Intervals
    cin >> n;
    vector<vector<int>> intervals;
    int temp;
    for(int i=0; i<n; i++){ 
        vector<int> row;
        for(int j=0; j<2; j++){
            cin >> temp;
            row.push_back(temp);
        }
        intervals.push_back(row);
    }
    
    vector<vector<int>> result = merge(intervals);
    
    for(int i=0; i<n; i++){ 
        cout << "| ";
        for(int j=0; j<2; j++){
            cout << result[i][j] << " "; 
        }
        cout << " |";
    }
    
    return 0;
}