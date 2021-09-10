/* Rotate a square matrix by 90 degree in clockwise direction without using any extra space
Given a square matrix, turn it by 90 degrees in clockwise direction without using any extra space.
Examples: 
Input:      
1 2 3   
4 5 6   
7 8 9   
Output 1 (for clockwise rotation): 
7 4 1   
8 5 2   
9 6 3   
Output 2 (for anti-clockwise rotation): 
3 6 9
2 5 8
1 4 7
*/      
#include<bits/stdc++.h>
using namespace std;

//Concepts: Transpose & Reversing Columns
// Rotating Matrix Anti-Clockwise
int main(){
    int m;
    cin >> m;
    int mat[m][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    
    // transpose in-place
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reversing in-place
    int k,j;
    for(int i=0;i<m;i++){
        j=0;
        k = m-1;
        while (j<k){
            swap(mat[j][i], mat[k][i]);
            j++;
            k--;
        }
    }
    cout << "\nThe Matrix After Rotation : \n\n";
    // print matrix
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}