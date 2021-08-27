/* Median in a row-wise sorted Matrix 
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5
Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median.  */

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution using Binary Search
// O(rlogc) Time Complexity instead of O(n^r*c)
int median(vector<vector<int>> &matrix, int r, int c){
    int mn = INT_MAX, mx = INT_MAX;
    for(int i=0;i<r;i++){
        mn = min(mn, matrix[i][0]);  // 1 Since, our matrix is row sorted
        mx = max(mx, matrix[i][c-1]);  // 9
    }
    int condition = (r*c +1)/2; // the median is to be greater than n/2 elements of the matrix and our given matic is a odd matrix.
    while(mn < mx){
        int mid = mn + (mx - mn) / 2, count = 0;
        for(int i=0;i<r;i++){
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if(count < condition){
            mn = mid+1;
        }
        else{
            mx = mid;
        }
    }
    return mn;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        cout << median(matrix, r, c) << endl;        
    }
    return 0;
}