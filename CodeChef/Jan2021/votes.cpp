#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        //A->John Jackson(friend)
        //B->Jack Johnson
        int n,m,n_votes=0,m_votes=0;
        cin>>n>>m;
        int A[n],B[m];
        for(int i=0;i<n;i++){
            cin>>A[i];
            n_votes+=A[i];
        }
        for(int i=0;i<m;i++){
            cin>>B[i];
            m_votes+=B[i];
        }
        //-1 if its impossible
        //0 if no swap needed
        if(n_votes == m_votes){
            cout<<0<<"\n";
            continue;
        }

    }

    return 0;
}