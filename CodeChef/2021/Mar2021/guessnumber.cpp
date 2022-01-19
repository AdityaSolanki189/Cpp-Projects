#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

void solve(){
    for(int i=1;i<=2000;i++){
        cout << i*i << "\n";
        int n; cin >>n;
        if (n==1)
            break;
        else
            continue;
    }
}

int main(){
    fastio();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}