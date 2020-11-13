#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll max = 1300000;
    bool prime[max]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=max; p++){ 
        if (prime[p] == true) { 
            for (ll i=p*p; i<=max; i += p) {
                prime[i] = false; 
            }
        } 
    } 

    ll T;
    cin>>T;
    while(T--){
        ll num;
        cin>>num;
        ll B[num+1];
        for(ll i=1;i<=num;i++) cin>>B[i];
        
        
        
        for(ll i=1;i<=num;i++) cout<<B[i]<<" ";
        cout<<endl;
    }
    return 0;
}