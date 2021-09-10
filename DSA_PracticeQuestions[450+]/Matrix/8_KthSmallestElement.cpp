/* Kth element in Matrix 
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =   {{16, 28, 60, 64},
             {22, 41, 63, 91},
             {27, 50, 87, 93},
             {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element. */

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int SortingMethod(int mat[MAX][MAX], int n, int k);
int BinarySearchMethod(int mat[MAX][MAX], int n, int k);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<SortingMethod(mat,n,r)<<endl;

        cout<<BinarySearchMethod(mat,n,r)<<endl;

    }
    return 0;
}

// O(nlogn) way is to create 1d array and sort it.
int kthSmallest1(int mat[MAX][MAX], int n, int k){
    int sz = n*n;
    int arr[sz], x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[x] = mat[i][j];
            x++;
        }    
    }
    sort(arr, arr+sz);
    return arr[k-1];
}
// O(logn) Time Complexity
int BinarySearchMethod(int a[MAX][MAX], int n, int k){
    if(n == 0)
        return 0;
    
    int start = a[0][0];
    int end = a[n-1][n-1];
    while (start < end){
        int cnt = 0, j;
        int mid = start+(end-start)/2;
        for(int row=0;row<n;row++){
            j = n-1;
            while (j>=0 && a[row][j] > mid){
                j--;
            }
            cnt += (j+1);
        }
        if(cnt < k)
            start = mid+1;
        else   
            end = mid;
    }
    return start;
}
