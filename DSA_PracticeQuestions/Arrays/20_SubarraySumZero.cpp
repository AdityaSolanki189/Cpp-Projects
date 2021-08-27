/* Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:
Input:
5
4 2 -3 1 6
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray 
with sum 0. */

#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n){
    int sum=0,i;
    unordered_map<int ,int> m;
    
    for(i=0; i<n; i++){
        sum += arr[i];
        
        if(sum == 0)
            break;
    
        if(m.find(sum)!=m.end())
            break;
            
        m[sum]++;
    }
    if(i == n)
        return false;
    else 
        return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)cin >> arr[i];
	    	
        if (subArrayExists(arr, n))
		    cout << "Yes\n";
	    else
		    cout << "No\n";
	}
    return 0;
}