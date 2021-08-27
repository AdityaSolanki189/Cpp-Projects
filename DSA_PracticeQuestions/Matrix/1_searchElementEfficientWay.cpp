/* Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
-> Integers in each row are sorted from left to right.
-> The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: 
    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: 
    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false */

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

// O(nlogn) TimeComplexity using Binary Search
bool Search1(vector<vector<int>>&v, int t){
    for(int i=0;i<(int)v.size();++i){
        if(binary_search(v[i].begin(), v[i].end(), t))
            return true;
    }
    return false;
}

/* O(m+n) Time Complexity 
    Below is an efficient solution that works in O(m + n) time.
    1) Start with the bottom left element
    2) Loop: compare this element e with x
        i) if they are equal then return its position
        ii) e x then move it to right (if out of bound of the matrix then break return false)
    3) repeat the i), ii) and iii) till you find an element or returned false     
*/
bool SearchEfficient(int mat[][MAX], int m, int n, int x) { 
    int i = m-1, j = 0;  //set indexes for bottom left element 
    while ( i >= 0 && j < n ){ 
        if ( mat[i][j] == x ) 
            return true; 

        if ( mat[i][j] > x ) 
            i--; 

        else //  if mat[i][j] < x 
            j++; 
    } 
    return false; 
} 

int main(){
    int m, n, target;
    cin >> m >> n >> target;
    vector<vector<int>> matrix;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }   
    }

    cout << Search1(matrix, target) << "\n";

    cout << SearchEfficient(matrix, target) << "\n";

    return 0;
}