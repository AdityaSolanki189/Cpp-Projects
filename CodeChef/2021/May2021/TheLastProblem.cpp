#include <bits/stdc++.h>
using namespace std;
int inf[1001][1001];

// precomputing the matrix (low constraints)
void pre(){
    for(int i=1; i<=1000; i++){
        inf[i][1] = i*(i+1)/2;

        for(int j=2; j<=1001; j++){
            inf[i][j] = inf[i][j-1] + (j-1) + (i-1);
        }
    }
}

void solve(){
    pre();

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int max_sum_path = 0;
    for(int r=x1; r<=x2; r++){
        max_sum_path += inf[r][y1];
    }

    for(int c=y1+1; c<=y2; c++){
        max_sum_path += inf[x2][c];
    }

    cout << max_sum_path << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}