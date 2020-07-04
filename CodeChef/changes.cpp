#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int money[N],n5=0,n10=0,nw=0;

        for(int i=1;i<=N;i++) cin>>money[i];

        for (int i = 1; i <= N; i++){
            if(money[i] == 5){
                n5 +=1;
                continue;
            }
            else if(money[i] == 10){
                n10 +=1;
                if(n5 >= 1){
                    n5 -=1;
                    continue;
                }
                else{
                    nw++;
                    break;
                }
            }
            else{ //15
                
                if(n10 >=1){
                    n10 -=1;
                    continue;
                }
                else if(n5 >= 2 ){
                    n5 -=2;
                    continue;
                }
                else{
                    nw++;
                    break;
                }
            }
        }
        if(nw>0)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}