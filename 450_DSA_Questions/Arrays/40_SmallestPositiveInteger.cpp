/* Smallest Positive Integer that can not be represented as Sum 
Given an array of size N, find the smallest positive integer value that cannot be represented as sum of some elements from the array.

Example 1:
Input: 
N = 6
array[] = {1, 10, 3, 11, 6, 15}
Output: 2
Explanation:
2 is the smallest integer value that cannot 
be represented as sum of elements from the array.

Example 2:
Input: 
N = 3
array[] = {1, 1, 1}
Output: 4
Explanation: 
1 is present in the array. 
2 can be created by combining two 1s.
3 can be created by combining three 1s.
4 is the smallest integer value that cannot be 
represented as sum of elements from the array. */

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    // O(nlogn) Time Complexity - un-sorted
    // O(n) - Sorted
    long long smallestpositive(vector<long long> array, long long n){
        sort(array.begin(), array.end());
        long long ans = 1, i=0;
        
        while(i < n && array[i] <= ans){
            ans += array[i];
            i++;
        }
        return ans;
    } 
};

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i){
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 