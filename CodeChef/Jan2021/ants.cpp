#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin>>T;
    while (T--){
        ll N,M;
        cin>>N>>M;
        ll arr[M];
        for (ll i=0;i<M;i++) cin>>arr[i];
        ll count_negative=0, count_positive=0, sum=0;
        if(N==1){
            sort(arr,arr+M);
            if(arr[0]>0) 
                cout<<0<<"\n";
            else if(arr[M-1]<0) 
                cout<<0<<"\n";
            else{
                for(ll i=0;i<M;i++){
                    if(arr[i]>0){
                        count_negative=i;
                        count_positive=M-i;
                        break;
                    }
                }
                while (count_negative>0 && count_positive>0){
                    sum += count_negative+count_positive -1;
                    count_negative --;
                    count_positive --;
                }
                cout<<sum<<"\n";
            }
        }
    }
	return 0;
}