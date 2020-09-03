#include <iostream>
#define ll long long
using namespace std;


void rotate(ll array[],ll n,ll k){
    ll left = n-k;
    while(left--){
        int temp = array[0];
        for(ll i=0;i<n-1;i++){
            array[i] = array[i+1];
        }
        array[n-1] = temp;
    }
}

int main(){
    ll n,k,q;
    cin>>n>>k>>q;
    ll array[n];
    ll m[q];
    for(ll i=0;i<n;i++) cin>>array[i];
    rotate(array,n,k);
    for(ll i=0;i<q;i++) cin>>m[i];
    
    for(ll i=0;i<q;i++){
        for(ll j=0;j<n;j++){
            if(m[i] == j){
                cout<<array[j]<<endl;
            }
        }
    }

    return 0;
}

//WITHOUT ACTUALLY ROTATING THE ARRAY - LOGICALLY//
/* 
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int array[n];
    for(int i=0;i<n;i++) cin>>array[i];
    
    for (int i = 0; i < q; i++) {
        int m;
        cin>>m;
        cout<<(array[(n - (k % n)+ m) % n])<<endl;
    }
}    */