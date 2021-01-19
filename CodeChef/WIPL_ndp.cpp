#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll check(ll x, ll a[], ll n){
    ll checksum[x+1]={'\0'};
    checksum[0]=1;
    for(ll i=0;i<n;i++){
        for(ll j=x;j>=a[i];j--){
            if(checksum[j-a[i]]==1)
                checksum[j]=1;
        }
    }
    return checksum[x];
}

ll Find_boxes(){
    ll n,k;
    cin>>n>>k;
    ll sum=0,ans=0;
    ll arr[n]={'\0'};
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr,arr+n,greater<>());
    if(n==1 || sum<2*k){
        cout<<"-1\n";
        return 0;
    }
    else if(sum==2*k){
        if(sum%2==1 || arr[0]>k){
            cout<<"-1\n";
            return 0;
        }
        else if(arr[0]==k)
            cout<<n<<"\n";
        else{
            if(check(k,arr,n)){
                cout<<n<<"\n";
                return 0;
            }
            else{
                cout<<"-1\n";
                return 0;
            }
        }
    }
    else if(arr[0]>=k){
        ans=1;
        ll Temp_sum=0;
        for(ll i=1;i<n;i++){
            Temp_sum+=arr[i];
            ans++;
            if(Temp_sum>=k){
                cout<<ans<<"\n";
                return 0;
            }
        }
    }
    else{
        ll Temp_sum=0;
        for(ll i=0;i<n;i++){
            Temp_sum+=arr[i];
            if(Temp_sum>=2*k){
                cout<<i+1<<"\n";
                return 0;
            }
        }
        cout<<"-1\n";
    }

}

int main(){
    ll Temp;
    cin>>Temp;
    while(Temp--){
        Find_boxes();
    }
    return 0;
}
