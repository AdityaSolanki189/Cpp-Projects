#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int fuel[N];
        for(int i=0;i<N;i++)cin>>fuel[i];
        int car = fuel[0];
        fuel[0] = 0;
        int i=1;
        int count=0;
        while(car!=0){
            if(fuel[i]!=0){
                car--; 
                car+=fuel[i];
                fuel[i]=0;
            }
            else{
                car--;
            }
            count++;
            i++;
        }
        cout<<count<<endl;
    }
    return 0;
}