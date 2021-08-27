/* FREQUENCY SORT
Given an array of integers. Write a code to sort an array elements in descending order of their frequency. If any two or more elements have same frequency then print the element which comes first.

Example 1:
    Input   : [5, 3, 4, 5, 8, 1, 1, 5]
    Output  : [5, 5, 5, 1, 1, 3, 4, 8]
    The frequency of elements are [5 : 3, 1 : 2, 3 : 1, 4 : 1, 8 : 1].
     
When we sort this array by frequency 5 comes first then 1. The element 3, 4 and 8 has same frequency.  So, we put these elements based on which element occur first in an array. 
     
   Example 2:
    Input  : [8, 2, 3, 4, 8, 2, 8, 2, 4, 5, 2, 9, 3]
    Output : [2, 2, 2, 2, 8, 8, 8, 3, 3, 4, 4, 5, 9]
    The frequency of elements are [ 2 : 4, 8 : 3, 3 : 2, 4 : 2, 5 : 1, 9 : 1].

When we sort this array the order is 2, 8, 3, 4, 5, 9. */

#include <bits/stdc++.h>
using namespace std;
 
bool fcompare(pair<int, pair<int, int> > p, pair<int, pair<int, int> > p1){
    if (p.second.second != p1.second.second)
        return (p.second.second > p1.second.second);
    else
        return (p.second.first < p1.second.first);
}

void sortByFrequency(int arr[], int n){
    unordered_map<int, pair<int, int> > hash; // hash map
    for (int i = 0; i < n; i++) {
        if (hash.find(arr[i]) != hash.end())
            hash[arr[i]].second++;
        else
            hash[arr[i]] = make_pair(i, 1);
    } 
 
    // Iterator to Traverse the Hashmap
    auto it = hash.begin();
 
    // Vector to store the Final Sorted order
    vector<pair<int, pair<int, int> > > b;

    for (it; it != hash.end(); ++it){
        b.push_back(make_pair(it->first, it->second));
    }

    sort(b.begin(), b.end(), fcompare);
 
    
    for (int i = 0; i < b.size(); i++) {
        int count = b[i].second.second;
        while (count--){
            cout << b[i].first << " ";
        }    
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    sortByFrequency(arr, n);
 
    return 0;
}