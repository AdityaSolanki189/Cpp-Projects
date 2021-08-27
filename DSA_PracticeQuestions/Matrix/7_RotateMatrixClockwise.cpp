/* Rotate a square matrix by 90 degree in clockwise direction "without using any extra space"
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
#define N 3

// Method1:
void rotate1(int a[N][N]){
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            // Swap elements of each cycle in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            cout << a[i][j] << " ";
        }    
        cout << '\n';
    }
}

// Method2: printing the matrix on the basis of observations made on indices.
void rotate2(int arr[N][N]){
    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i >= 0; i--){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    int mat[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> mat[i][j];
        }
    }
    
    // rotate1(mat);

    rotate2(mat);

    return 0;
}