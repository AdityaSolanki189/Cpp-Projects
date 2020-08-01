#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define ld long double
//Number of digits in N =floor(log10(N)) + 1;  
const ll MOD=1000*1000*1000+7;
ll mulmod(ll a, ll b, ll mod) 
{ 
    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() { fastio();
	// your code goes here
	int t; cin>>t;
	while(t--){
	   int n,k;
	   cin>>n>>k;
	   int P[n];
	   int loss=0;
	   for(int i=0;i<n;i++)
	   {
	      cin>>P[i];
	      if (P[i]>k)
	      {
	         loss=loss+P[i]-k;
	      }
	   }
	   cout<<loss<<"\n";
	}

	return 0;
}

