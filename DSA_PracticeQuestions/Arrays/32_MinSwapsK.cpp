/* Minimum swaps and K together 
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Example 1:
Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1
Explanation:
To bring elements 2, 1, 3 together, swap element '5' with '3'
such that final array will be- arr[] = {2, 1, 3, 6, 5}

Example 2:
Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
Output :  2  */

#include<bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k) {
    int count=0;
    for(int i=0;i<n;++i){
        if(arr[i] <= k)
            ++count;
    }
    int greater = 0;
    for(int i=0;i<count;i++){
        if(arr[i] > k)
            ++greater;
    }
    int ans = greater;  
    for(int i=0,j=count;j<n;++i,++j){
        if(arr[i] > k)
            --greater;
        if(arr[j] > k)
            ++greater;
        ans = min(ans, greater);
    }
    return ans;
}

int main() {
	int t,n,k;
	cin>>t;
	while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}


