/* Given two arrays: a1[0..m-1] of size m and a2[0..n-1] of size n. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.

Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}    //sort : 1, 3, 7, 11, 13, 21
a2[] = {11, 3, 7, 1}            //sort : 1, 7, 11
Output:
Yes
Explanation:
a2[] is a subset of a1[] */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// Solving Using Maps
void isSub_maps(){
    ll n, m, i;
    cin >> m >> n;
    ll a1[m], a2[n];

    unordered_map<ll,ll> m1, m2;
    
    for(i=0;i<m;i++) {
        cin >> a1[i];
        m1[a1[i]]++;
    }
    for(i=0;i<n;i++){
        cin >> a2[i];
        m2[a2[i]]++;
    }

    // Since, we have to check whether a2 is subset of a1 or not
    for(i=0;i<n;i++){
        if(m1[a2[i]] < m2[a2[i]]) // if a2 is subset then all its elements are less than a2s'
            break;
    }

    if(i == n)
        cout << "Yes" << "\n";
    else 
        cout << "No" << "\n";
}

// Using Sorting Approach
bool isSub_sort(ll a1[], ll a2[], ll m, ll n){
    if(m < n) return false;

    sort(a1, a1+m);
    sort(a2, a2+n);
    ll i=0, j=0;

    while(i<m && j<n){
        if(a1[i] < a2[j]){
            i++;
        }    
        else if(a1[i] == a2[j]){
            i++;
            j++;
        }
        else if(a1[i] > a2[j]) //that element is not present in a1.
            return false;
    }
    if(j == n)
        return true;
    return false;
}
 
int main(){

    isSub_maps(); // using map data structure (hash tables for easier approach)

    ll n, m, i;
    cin >> n >> m;
    ll a1[n], a2[m];

    for(i=0;i<m;i++) cin >> a1[i];
    
    for(i=0;i<n;i++) cin >> a2[i];

    if(isSub_sort) // general approach using sorting method(nlogn time cmpx.)
        cout << "Yes" << "\n";
    else 
        cout << "No" << "\n";

    return 0;
}