#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        ll N,K,sum=0,count=0;
        cin>>N>>K;
        ll H[N];
        for(ll i=0;i<N;i++) cin>>H[i];
        sort(H,H+N,greater<int>());
        ll sum_mike=0,sum_tracy=0;
        for(ll i=0;i<N;i++)sum+=H[i];
        if(sum >= 2*K){
            ll curr=0;
            
        }
        cout<<count<<"\n";
    }
    return 0;
}