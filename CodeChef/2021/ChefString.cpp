#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int str[N];
        for(int i=1;i<=N;i++){ 
            cin>>str[i];
        }
        int skip = 0,f,s,diff;
        for(int i=1;i<N;i++){
            f=0;s=0,diff=0;
            f = str[i];
            s = str[i+1];
            diff = f-s;
            skip += abs(diff)-1;
        }
        cout<<skip<<endl;
    }
    return 0;
}