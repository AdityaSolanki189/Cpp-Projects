#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll max = 1300000;
    bool prime[max]; 
    memset(prime, true, sizeof(prime)); 
    //prime
    prime[0] = false;
    prime[1] = false;
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
        
        ll A[num]; //store it with all primes
        ll index = 1;
        for (ll p=2; p<=max; p++) {
            if(index<=num){  
                if (prime[p]){ 
                    A[index] = p;
                    index++;
                }
            }
            else{
                break;
            }
        }
        
        ll B[num];
        for(ll j=1;j<=num;j++) cin>>B[j];

        for(int i=1;i<=num;i++){
            if(i != B[i]){
                A[i] = A[B[i]];
            }
        }
        for(int i=1;i<=num;i++) cout<<A[i]<<" ";
        cout<<endl;
    }
    return 0;
}