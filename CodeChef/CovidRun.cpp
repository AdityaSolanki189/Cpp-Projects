#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        if(k == 1) cout<<"YES"<<endl;
        cout<<(x+k)%n;
        /* for(int i=0;i<n;i++){
            
        } */
    }
}