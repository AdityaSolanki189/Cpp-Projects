/* A drawer contains socks of n different colours. The number of socks available of ith colour is given by a[i] where a is an array of n elements. Tony wants to take k pairs of socks out of the drawer. However, he cannot see the colour of the sock that he is picking. You have to tell what is the minimum number of socks Tony has to pick in one attempt from the drawer such that he can be absolutely sure, without seeing their colours, that he will have at least k matching pairs.

Example 1:
Input:
N = 4, K = 6
a[] = {3, 4, 5, 3}
Output: 15
Explanation: 
All 15 socks have to be picked in order
to obtain 6 pairs.

Example 2:
Input: N = 2, K = 3
a[] = {4, 6}
Output: 7
Explanation: The Worst case scenario after 6
picks can be {3,3} or {1,5} of each
coloured socks. Hence 7th pick will ensure
3rd pair. */

#include <bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int find_min(int a[], int n, int k) {
        int opt=0, res=-1, pairs=0;
        for(int i=0;i<n;i++){
            pairs += a[i]/2;
            
            if(a[i]%2 == 0)
                opt += (a[i]-2)/2;
            else
                opt += (a[i]-1)/2;
        }
        if(pairs < k)
            return res;
        
        if(k <= opt)
            return (2*(k-1) + n +1);  
        else
            return (2*opt + n + k - opt);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}