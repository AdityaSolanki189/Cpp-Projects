/* Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6. */

//Use Hashing STL: unordered_map

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int getPairsCount(int arr[], int n, int k){
        int count=0,i;
        unordered_map<int, int> map;
        
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            count += map[k-arr[i]];
            if(k-arr[i] == arr[i]){
                count--;
            }
        }
        return count/2;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    