#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 10000006

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    
    int T;
    cin>>T;
    while(T--){   
        ll N;
        cin>>N;
        int B[N];
        for(int i=1;i<=N;i++) cin>>B[i];
        int A[N];
        int index=1;
        bool flag;
        for(int i=1;i<=max;i++){
            if(index<=N){    
                if(i==1||i==0) continue;
                flag = true;
                for(int j=2;j<=i/2;j++){
                    if(i%j==0) {
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    A[index] = i;
                    index++;
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(i != B[i]){
                A[i] = A[B[i]];
            }
        }
        for(int i=1;i<=N;i++) cout<<A[i]<<" ";
        cout<<endl;
    }
    return 0;
}