//Find the Max. Subarray Sum of the Array of Size K.

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	int i,n,k;
    cin>>n>>k;

    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];

    int max=0, sum=0;
    for(i=0;i<k-1;i++)  sum += arr[i];
    max = sum;

    int l=0,r=k-1;

    while(r<=n-2){
        r++;
        sum += arr[r];
        sum -= arr[l];
        l++;
        if(max<sum) max = sum;
    }

    cout<<max<<endl;

	return 0 ; 
}