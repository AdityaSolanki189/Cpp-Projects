#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;
        int price[N];
        for(int i=1;i<=N;i++) cin>>price[i];
        int rev_loss = 0,loss;
        for(int i=1;i<=N;i++){
            if(price[i] > K){
                loss = price[i]-K;
                rev_loss += loss;
                continue;   
            }
        }
        cout<<rev_loss<<endl;
    }
    return 0;
}