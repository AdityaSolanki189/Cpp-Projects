#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int r, c, x;
        cin >> r >> c >> x;
        int A[r][c], B[r][c];
        int sumA=0, sumB=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> A[i][j];
                sumA += A[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> B[i][j];
            }
        }

        //Solving for 2x2 matrix

    }
}