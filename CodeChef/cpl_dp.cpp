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
    for(ll i=0;i<n;i++){
        
    }
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
        sort(arr,arr+n);
        if(N == 1){
            cout<<"-1"<<endl;
        }
    }

    return 0;
}