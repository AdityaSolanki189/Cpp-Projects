/* Say that you are a traveler on a 2D grid. You begin your journey in the top-left corner and your goal is to travel to the bottom-right corner. You may only move down or right.
In how many ways can you travel to the goal on a grid with dimensions m*n?
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// naive recursive
// Time Complexity : O(2^n+m)
// Space Complexity : O(n+m)
int gridTraveler(int m, int n){
    if(m == 1 && n == 1) return 1;
    if(m == 0 || n == 0) return 0;

    return gridTraveler(m-1, n) + gridTraveler(m, n-1);
}

int dp[500][500] = {0};

// recursion + memoization (DP approach)
// Time Complexity : O(m*n), better than the recursive only approach
// Space Complexity : O(n+m)
int gridTraveler_DP(int m, int n){
    if(m == 1 && n == 1) return 1;
    if(m == 0 || n == 0) return 0;

    // check if already computed
    if(dp[m][n] != 0) return dp[m][n];

    // gridTraveler(a,b) == gridTraveler(b,a)
    dp[m][n] = dp[n][m] = gridTraveler(m-1, n) + gridTraveler(m, n-1);
    return dp[m][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;

        //cout << gridTraveler(m, n) << "\n";

        cout << gridTraveler_DP(m, n) << "\n";   
    }
    return 0;
}