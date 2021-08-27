/* Row with max 1s 
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing). */

#include<bits/stdc++.h>
using namespace std;

// Solving in Efficient Way Brute Force +
// O(N+M) Time Complexity
int rowWithMax1s(vector<vector<int> > matrix, int n, int m) {
    for(int i=0;i<n;i++){
        if(matrix[i][0] == 1)
            return i;
    }
    int max = -1;
    int i=0, j = m-1;
    while(i<n && j>=0){
        if(matrix[i][j] == 1){
            max = i;  //store i with max 1s
            j--;
        }
        else
            i++;
    }
    return max;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        auto ans = rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}