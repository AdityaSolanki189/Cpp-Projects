#include <iostream>
#include <cmath>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll n,i,k,day=0;
        cin>>n>>k;
        ll arr_Q[n];
        for(i=0;i<n;i++){ 
            cin>>arr_Q[i];
        }
        for(i=0;i<n;i++){
            if(arr_Q[i]>=k){
                day++;
                arr_Q[i+1] += (arr_Q[i]-k);
            }
            if(arr_Q[i]<k) break;
        }
        if(i == n){  
            day = day + floor((arr_Q[n-1]-k)/k);
        }
        cout<<day+1<<endl;
    }
}