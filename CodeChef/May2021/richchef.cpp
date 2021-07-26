#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,x;
    cin >>a>>b>>x;

    cout << (b-a)/x << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}