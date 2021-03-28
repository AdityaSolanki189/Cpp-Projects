
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
    int a, y, x;
    cin >> a >> y >> x;
    int time = 0;
    if(a == 0){
        return 1;
    }
    else if(a < y){
        return ((a*x)+1);
    }
    else    return x*y;   
}

int main(){
    fastio();
    int t; cin >> t;
    while(t--){
        cout << solve() << "\n";
    }
    return 0;
}