
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
    ll x, r, m;
    cin >> x >> r >> m;
    // to seconds
    ll goal = 60*r;
    ll max = m*60;
    ll rem = goal-x;

    if(x >= goal){
        if(r <= m)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    else{
        if(x + 2*(rem) <= max)
            cout << "YES" << "\n";
        else 
            cout << "NO" << "\n";
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