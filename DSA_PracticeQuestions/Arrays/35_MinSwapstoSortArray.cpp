/* Minimum number of swaps required to sort an array
Difficulty Level : Hard
 Last Updated : 08 Mar, 2021
Given an array of n distinct elements, find the minimum number of swaps required to sort the array.

Examples: 

Input : {4, 3, 2, 1}
Output : 2
Explanation : Swap index 0 with 3 and 1 with 2 to 
              form the sorted array {1, 2, 3, 4}.

Input : {1, 5, 4, 3, 2}
Output : 2 */

#include<bits/stdc++.h>
using namespace std;

int minSwaps(int array[], int n){
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = array[i];
        arrPos[i].second = i;
    }
 
    sort(arrPos, arrPos + n);
 
    vector<bool> vis(n, false);

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j]){
            vis[j] = 1;
 
            j = arrPos[j].second;
            cycle_size++;
        }
 
        if (cycle_size > 0){
            ans += (cycle_size - 1);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];
    
    cout << minSwaps(array, n) << "\n";
    return 0;
}