#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll l,h;
    cin >> l >>h;
    string s;
    cin >> s;
    bool condition=false;
    ll zeroes = 0; 
    ll req_sleep = h;
    for(int i=0;i<l;i++){
        if(s[i] == '0')
            zeroes++;
        else{
            if(zeroes == req_sleep || zeroes == h){
                condition=true;
                break;
            }
            if((h-zeroes)*2 < h){
                h = 2*(h-zeroes);
            }
            zeroes = 0;
        }
    }
    if(condition || (zeroes == req_sleep) || (zeroes == h)){
        cout << "Yes\n";
        return;
    }
    else{
        h = 2*(h-zeroes);
        if(h <= 0){
            cout << "Yes\n";
            return;
        }
        else{
            cout << "No\n";
            return;
        }
    }
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