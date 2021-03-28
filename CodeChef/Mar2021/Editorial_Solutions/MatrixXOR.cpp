// March CookOff 2021
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// Using x^x = 0, 0^x = x.
void solve(){
    ll n, m ,k;
    cin >> n >> m >> k;
    ll res=0;
    // for 1st column elements
    for(ll i=1;i<=n;i++){
        if(min(i,m) % 2 == 1)
            res ^= k+i+1;
    }

    // for last row elements
    for(ll j=2;j<=m;j++){
        if(min(n, m-j+1) % 2 == 1)
            res ^= k+n+j;
    }
    cout << res << "\n";
}

int main(){
    fastio();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}