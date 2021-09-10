/* Common elements in all rows of a given matrix
Difficulty Level : Medium
Time Complexity : O(m*n)
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

Example:
Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows. */

#include<bits/stdc++.h>
using namespace std;

// Using maps
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> m;
    // maps help us in telling if an element is present in every row or not.
    int r, c;
    cin >> r >> c;
    int mat[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat[i][j];
        }
    }

    for(int i=0;i<r;i++){
        m[mat[0][j]] = 1;
    }

    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(m[mat[i][j]] == i){
                m[mat[i][j]] = i+1;
                if(i == r-1){
                    cout << mat[i][j] << " ";
                }
            }
        }
    }
    return 0;
}