//https://codeforces.com/problemset/problem/1341/B
// 1 based indexing, arr[i-1]<peak>arr[i+1], pieces = peaks +1.

#include <iostream>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    int mts[n];
    for(int i=0;i<n;i++) cin>>mts[i];

    int peaks=0;
    for(int i=1;i<k-1;i++){
        if(mts[i]>mts[i-1] && mts[i]>mts[i+1])
            peaks++;
    }

    int max_peaks = peaks;
    int start_index=0;

    int l=0, r=k-1;

    while(r<=n-2){
        if(mts[r]>mts[r-1] && mts[r]>mts[r+1])
            peaks++;
        r++;
        l++;   
        if(mts[l]>mts[l-1] && mts[l]>mts[l+1])
            peaks--;
          
        if(peaks>max_peaks){
            max_peaks = peaks;
            start_index = l;
        }
    }
    cout<<max_peaks+1<<" "<<start_index+1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

    int t;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}