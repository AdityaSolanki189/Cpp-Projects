#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define INF 10000000000000000
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i=0; i<n; i++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define vi vector<int>
#define ss second
#define ff first
#define pii pair<int,int>
#define vii vector<pii>
#define gethash(l, r) (MOD-(h[r+1]*p_pow[r-l+1])%MOD+h[l])%MOD;

using namespace __gnu_pbds;
using namespace std;

//const int N = 1e3+5;
//int arr[N][N];

void solve(int test){
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    int y;
    cin>>y;
    int res = abs(y-a)+c+abs(b-y);
    n--;
    while(n--){
        cin>>y;
        res = min(res,abs(y-a)+c+abs(y-b));
    }
    cout<<res<<endl;
}

signed main()
{
    fastIO
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        solve(i);
    }
    return 0;
}
