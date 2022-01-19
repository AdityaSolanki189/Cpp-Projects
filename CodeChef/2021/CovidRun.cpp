#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,x,y,j=0;
        cin>>n>>k>>x>>y;
        if(k == 1) cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            if((x+k*i)%n == y){
                cout<<"YES"<<endl;
                j=1;
                break;
            }
        }
        if(j==0) cout<<"NO"<<endl;
    }
    return 0;
}