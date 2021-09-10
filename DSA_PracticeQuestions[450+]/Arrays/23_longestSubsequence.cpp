/* Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence. */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        ll nums, cnt=0, max_track=0, a, h[100005]={0};
        for(int i=0;i<n;i++){
            cin >> a;
            h[a] = 1;
            nums = max(nums, a);
        }

        for(int i=0;i<=nums;i++){
            if(h[i] == 1) cnt++
            else{
                max_track = max(max_track, cnt);
                cnt = 0;
            }
        }

        max_track = max(max_track, cnt);

        cout << max_track << "\n";
    } 
    return 0;
}