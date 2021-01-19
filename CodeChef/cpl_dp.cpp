#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
ll DP[4020][4020];
ll pref[4020];

ll D_fn(ll id,ll taken,ll n,ll k,vll arr){
    if(taken>=k && (pref[id]-taken >= k)) return 0;
    if(id>=n) return 1e10;
    if(DP[id][taken]!=-1) return DP[id][taken];

    ll C1= D_fn(id+1,min(taken+arr[id],pref[id]-taken),n,k,arr);
    ll C2= D_fn(id+1,min(pref[id]-taken+arr[id],taken),n,k,arr);
    return DP[id][taken] = 1+min(C1,C2);
}

ll givemedp(vll &arr,ll n,ll k){
    for(ll i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
    for(ll i=0;i<=(n+10);i++){
        pref[i] = 0;
        for(ll j=0;j<=k+10) DP[i][j]=-1;
    }
    for(ll i=1;i<=n;i++){
        pref[i] = pref[i-1]+arr[i-1];
    }
    ll ans = D_fn(0,0,n,k,arr);
    return ans>1e9?-1:ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin>>T;
    while(T--){
        ll N,K;
        cin>>N,K;
        vector<ll> arr;
        arr.assign(N,0);
        for(ll i=0;i<N;i++) cin>>arr[i];
        sort(arr,arr+N);
        if(N == 1){
            cout<<"-1"<<endl;
        }
    }

    return 0;
}