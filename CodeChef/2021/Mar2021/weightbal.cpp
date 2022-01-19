#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
    int w1,w2,x1,x2,m;
    cin >> w1>> w2>> x1>> x2>> m;
    int min = w1, max = w1;
    min += x1*m;
    max += x2*m;
    if(w2>=min && w2<=max)
        cout << 1;
    else    
        cout << 0;
    cout << "\n";
}

int main(){
    fastio();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}