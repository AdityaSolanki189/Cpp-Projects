#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        //A->John Jackson(friend) ;n
        //B->Jack Johnson         ;m
        ll n,m,n_votes=0,m_votes=0;
        cin>>n>>m;
        ll A[n],B[m];
        for(ll i=0;i<n;i++){
            cin>>A[i];
            n_votes+=A[i];
        }
        for(ll i=0;i<m;i++){
            cin>>B[i];
            m_votes+=B[i];
        }
        //-1 if its impossible
        //0 if no swap needed
        if(n_votes > m_votes){
            cout<<0<<"\n";
            continue;
        }

        sort(A,A+n);
        sort(B,B+m,greater<int>());
        ll flag=0,swaps=0,min=0,max=0;
        for(ll i=0;i<n;i++){
            min = A[i];
            max = B[i];
            n_votes-=min;
            n_votes+=max;
            m_votes-=max;
            m_votes+=min;
            swaps++;
            if(n_votes>m_votes){
                flag=1;
                cout<<swaps<<"\n";   
                break;
            }
        }
        
        if(flag==0)
            cout<<-1<<"\n";
    }
    return 0;
}