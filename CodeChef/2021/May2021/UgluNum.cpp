#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
string decToBinary(int n){
    string binarystr = "";
    int Binary[32];
 
    int i = 0;
    while (n > 0) {
        Binary[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    for (int j = i - 1; j >= 0; j--){
        cout << Binary[j];
        binarystr += Binary[j];
    }
    return binarystr;
}

void permute(vector<int> a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}

void solve(){
    ll N;
    cin >> N;
    
    vector<ll> arr(N);
    for(ll i=0;i<N;i++){
        cin >> arr[i];
    }
    
    permute()


    cout << "\n";
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