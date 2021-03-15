#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,h,x;  //H->hours need, x->Hours left
        cin >> n >> h >> x;
        int time[n];
        for(int i=0;i<n;i++) cin >> time[i];
        bool flag=false;
        for(int i=0;i<n;i++){
            if(time[i]+x >= h){
                flag = true;
                break;
            }
        }
        if(flag == false){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }

    }
    return 0;
}