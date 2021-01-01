#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void swap(ll n1, ll n2) {
    ll temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

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
        if(n_votes == m_votes){
            cout<<0<<"\n";
            continue;
        }
        /* ll dif = m_votes-n_votes;
        sort(A,A+n);
        sort(B,B+m); */
        ll swaps=0;
        while(n_votes>m_votes){
            ll n1 = min_element(A,A+n);
            ll n2 = max_element(B,B+m);
            swap(n1,n2);
            swaps++;
        }
        cout<<swaps<<"\n";
    }
    return 0;
}