#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

int solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int total = n + m,cnt = 1,tmp = abs(n - m) + 1,res = 0;
    bool incrementer = true;
    for (int i = 2; i <= total; i++) {
        if (cnt % 2) 
            res ^= (k + i);
        if (cnt == min(m, n) && tmp > 0) {
            tmp--;
            if (tmp == 0) {
                incrementer = false;
                cnt--;
            }
        }
        else if (incrementer) 
            cnt++;
        else 
            cnt--;
    }
    return res;
}

int main(){
    fastio();
    int t; cin >> t;
    while(t--){
        cout << solve() << "\n";
    }
    return 0;
}
