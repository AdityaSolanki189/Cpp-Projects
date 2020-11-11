#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        int B[N];
        for(int i=1;i<=N;i++) cin>>A[i];
        for(int i=1;i<=N;i++){
            for(int j=N;j>0;j--){
                if(A[j]%A[i] == 0){
                    B[i] = j;
                    break;
                }
            }
        }
        for(int i=1;i<=N;i++) cout<<B[i]<<endl;
    }

    return 0;
}