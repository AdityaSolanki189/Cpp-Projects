#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fastio();
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll n = (int)s.size();
        bool len = false, low = false, up = false, dig = false, sp = false;

        if(n >= 10) len = true;
        // Note : up, dig, sp check from i=1 to i=n-2
        for(ll i=0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z') low = true;
            if(i!=0 && i!=n-2){
                if(s[i] >= 'A' && s[i] <= 'Z') up  = true;
                if(s[i] >= '0' && s[i] <= '9') dig = true;
                if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '&' || s[i] == '?') sp = true;
            }
        }

        if(low && up && len && dig && sp)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}

/* 3
#cookOff#P1
U@code4CHEFINA
gR3@tPWD */