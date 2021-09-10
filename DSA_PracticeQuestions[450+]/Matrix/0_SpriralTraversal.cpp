/* Spirally traversing a matrix 
Medium Accuracy: 48.39% Submissions: 23515 Points: 4
Given a matrix of size R*C. Traverse the matrix in spiral form.
Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 */

#include<bits/stdc++.h>
using namespace std;

// O(r*c) Time Complexity
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    vector<int> result;
    int k=0,l=0;
    while(k<r && l<c){
        // First Row of remaining rows
        for(int i=l;i<c;++i){
            result.push_back(matrix[k][i]);
        }
        k++;
        // last column form remaining columns
        for(int i=k;i<r;++i){
            result.push_back(matrix[i][c-1]);
        }
        c--;
        // last row from remaining rows
        if(k < r){
            for(int i=c-1;i>=l;--i){
                result.push_back(matrix[r-1][i]);
            }
            r--;
        }   
        // first column from remaining column
        if(l < c){
            for(int i=r-1;i>=k;--i){
                result.push_back(matrix[i][l]);
            }
            l++;
        }
    }
    return result;
}

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++){
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++){
                cin >> matrix[i][j];
            }
        }

        vector<int> result = spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i){
            cout << result[i] << " ";
        }    
        cout << "\n";
    }
    return 0;
}