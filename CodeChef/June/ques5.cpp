#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve_queries(vector<ll> v, ll q){
    while(q--){
        ll l,r,x,ch;
        cin >> ch;
        if(ch == 1){
            cin >> l >> r >>x;
            for(ll j=l-1;j<r;j++){
                v[j] = v[j] + (x+j+1-l) * (x+j+1-l);
            }
        }
        else{
            ll y;
            cin >> y;
            cout << v[y-1] << "\n";
        }
    }
}

void solve(){
    ll n,q;
    cin >> n >>q;

    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll val;
        cin >> val;
        v.push_back(val);
    }

    solve_queries(v, q);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}