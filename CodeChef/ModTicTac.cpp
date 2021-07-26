#include <bits/stdc++.h>
using namespace std;
int plays[1000][1000];

void solve(){
    int m, n, k;
    cin >> m >> n >> k;

    int x, y;
    for(int i=0;i<(m*n);i++){
        cin >> x >> y;
        if(i%2==0)
            plays[x][y] = 0; // Alice
        else   
            plays[x][y] = 1; // Bob
    }

    

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