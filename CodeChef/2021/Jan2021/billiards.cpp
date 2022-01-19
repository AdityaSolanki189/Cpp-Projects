#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       
    ll t;
    cin>>t;
    while(t--){
        //Ball Co-ordinates -> x,y
        //Board Co-ordinates -> {(0,0),(0,N),(N,N),(N,0)}
        ll N,K,x,y;
        cin>>N>>K>>x>>y;

        if(x == y){
            cout<<N<<" "<<N<<"\n";
            continue;
        }
        if(x<y){
            K= K%4; //will loop again
            if(K == 1){
                cout<<(x+N-y)<<" "<<N<<"\n";
            }
            else if(K == 2){
                cout<<N<<" "<<(x+N-y)<<"\n";
            }
            else if(K == 3){
                cout<<0<<" "<<(y-x)<<"\n";
            }
            else{
                cout<<(y-x)<<" "<<0<<"\n";
            }
        }
        else{ //when (x>y)
            K= K%4; //will loop again
            if(K == 1){
                cout<<N<<" "<<(y+N-x)<<"\n";
            }
            else if(K == 2){
                cout<<(y+N-x)<<" "<<N<<"\n";
            }
            else if(K == 3){
                cout<<0<<" "<<(x-y)<<"\n";
            }
            else{
                cout<<(x-y)<<" "<<0<<"\n";
            }
        }
    }
    return 0;
}