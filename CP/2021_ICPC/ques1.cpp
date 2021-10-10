#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=1;i<=n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6+13, M = N;
//=======================
vi g[N];
int a[N];
int i,j, n, m, k;
//=======================

bool isPairSum(int A[], int N, int X){
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (i == j)
                continue;
            if (A[i] + A[j] == X)
                return true;
            if (A[i] + A[j] > X)
                break;
        }
    }
    return false;
}

void solve() {
    cin>>n;
	cin>>k;
	int A[n];
	for(i=0;i<n;i++) cin>>A[i];
	sort(A,A+n);
	if(isPairSum(A,n,k)){
		cout<<"PERFECT\n";
	}
	else	cout<<"IMPERFECT\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
    //solve();

    return 0;
}