/* Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
Example 1:
    Input:
    N = 5
    Arr[] = {6, -3, -10, 0, 2}
    Output: 180
    Explanation: Subarray with maximum product
    is  6, -3, -10 which gives product as 180. 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll maxProduct(ll *arr, ll n) {
    ll x, y, z, maxx = arr[0], minn = arr[0], res = arr[0];

    for(ll i=1; i<n; i++) {
        x = arr[i];
        y = maxx*x;
        z = minn*x;
        
        maxx = max(x, max(y,z));
        minn = min(x, min(y,z));
        res = max(res, max(maxx, minn));
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, i;
        cin >> n;
        ll arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll ans = maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}