/* William Macfarlane wants to look at an array.
You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the sum of every number between the range [i, j] (inclusive).
Note: the query ranges are specified using 0-based indexing.
**Simple PREFIX SUM Problem with Coditions**
Input
The first line contains N, the number of integers in our list (N <= 100,000). The next line holds N numbers that are guaranteed to fit inside an integer. Following the list is a number Q (Q <= 10,000). The next Q lines each contain two numbers i and j which specify a query you must answer (0 <= i, j <= N-1).

Output
For each query, output the answer to that query on its own line in the order the queries were made.

Example,
Input:
3
1 4 1
3
1 1
1 2
0 2
Output:
4
5
6 */

#include <bits/stdc++.h>
using namespace std;
//#define fo(i,n) for(i=0;i<n;i++)

//Brute Force - Naive Approach (For High Time Constraint) : TC = O(n) + O((R-L+1)*q)
/* int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n,i;
	cin>>n;
    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];

    int q;
    cin>>q;
    while(q--){
        int l,r,sum=0;
        cin>>l>>r;
        for(i=l;i<=r;i++){
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }

	return 0 ; 
} */

//Efficient Approach - Prefix Sum : TC = O(n)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    int pre[n];
    for (i = 0; i < n; i++){
        if (i == 0)
            pre[i] = arr[i];
        else
            pre[i] = pre[i - 1] + arr[i];
    }

    int q;
    cin >> q;
    while (q--){
        int l, r, sum = 0;
        cin >> l >> r;
        if (l == 0)
            cout << pre[r] << endl;
        else
            cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}