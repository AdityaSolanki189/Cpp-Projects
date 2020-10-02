#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll n,k,arr_Q[100000],sum=0;
        cin>>n>>k;
        for(ll i=0;i<n;i++){ 
            cin>>arr_Q[i];
            sum+=arr_Q[i];
        }
        ll day = floor(sum/k);
        cout<<day+1<<endl;
    }
}