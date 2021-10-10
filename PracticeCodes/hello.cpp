#include <bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;
    int len = str.length();

    if(len <= 10){
        cout<<str<<endl;
        return;
    }
    else{
        cout<<str[0]<<len-2<<str[len-1]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie();

    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}