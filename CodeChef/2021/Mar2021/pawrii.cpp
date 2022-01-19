#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
    string str;
    cin >> str;
    int len = str.size();
    for(int i=0; i<len-4;i++){
        if(str[i] == 'p' && str[i+1] == 'a' && str[i+2] == 'r' && str[i+3] == 't' && str[i+4] == 'y'){
            str[i+2] = 'w';
            str[i+3] = 'r';
            str[i+4] = 'i';
        }
    }
    cout << str << "\n";
}

int main(){
    fastio();
    int t; cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
    return 0;
}