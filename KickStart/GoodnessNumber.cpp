#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, cc = 1;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int ans = 0;
        for(int i=0;i<n/2;++i){
            ans += (str[i] != str[n-1-i]);
        }
        cout << "Case #" << cc << ": " << abs(ans-k) << endl;
        cc++;
    }
    return 0;
}