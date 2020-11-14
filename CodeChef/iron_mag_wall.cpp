#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin>>T;
    while(T--){
        ll N,K;
        queue<ll> M;
        queue<ll> I;
        string S;
        cin>>N>>K;
        cin.ignore();
        cin>>S;
        ll ans=0;

        for(ll i = 0;i<N;i++){

            if(S[i] == 'M'){
                M.push(i);
            }
            if(S[i] == 'I'){
                I.push(i);
            }
            if(S[i] == 'X' || i == N-1){

                ll l=0,r=0,sheet;
                while(!M.empty() && !I.empty()){

                    sheet=0;
                    l = min(M.front(),I.front());
                    r = max(M.front(),I.front());

                    for(ll j=l;j<=r;j++){
                        if(S[j] == ':')
                            sheet++;
                    }

                    if(((K+1)-abs(l-r)-sheet) > 0){
                        ans++;
                        M.pop();
                        I.pop();
                    }
                    else if(M.front() < I.front())
                        M.pop();
                    else I.pop();
                }
                while(!M.empty()) M.pop();
                while(!I.empty()) I.pop();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}