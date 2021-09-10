/* Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}   //sorted : 1,3,4,7,9,9,12,56
Output: 6
Explanation: The minimum difference between 
maximum chocolates and minimum chocolates 
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}. */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


ll getMinDif(vector<ll> &v, ll n, ll m){
    ll mn = INT_MAX, i, j=0;
    sort(v.begin(), v.end());

    for(i = m-1; i<n; i++){
        mn = min(mn, v[i]-v[j]);  
        j++;
    }
    return mn;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        ll n, m, x, i;
        cin >> n >> m;
        vector<ll> vec;
        for(i=0;i<n;i++){
            cin >> x;
            vec.push_back(x);
        }

        cout << getMinDif(vec, n, m) << "\n";
    }
    return 0;
}