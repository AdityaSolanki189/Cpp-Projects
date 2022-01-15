//https://www.codechef.com/COW42020/problems/COW3E/

/* Sample Input:
3 3 2 2
1 2 3
1 1 0
4 -2 2
2 0 0 1 1
-1 1 0 2 2
0 0 0 1
1 1 2 2

Sample Output:
7
-1 */

#include <bits/stdc++.h>
using namespace std;
//#define fo(i,n) for(i=0;i<n;i++)

//Brute Force - Naive Approach (For High Time Constraint) : TC = O(q*n*m)
int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n,m,u,q,i,j;
	cin>>n>>m>>u>>q;
    int arr[n][m];
    for(i=0;i<n;i++){ 
        for(j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2,sum=0;
        cin>>x1>>y1>>x2>>y2;
        for(i=x1;i<x2;i++){ 
            for(j=y1;j<y2;j++){
                sum+=arr[i][j];
            }
        }
    }

	return 0 ; 
}

//Efficient Approach - Prefix Sum : TC = O(n)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,u,q,i,j;
	cin>>n>>m>>u>>q;
    int arr[n][m];
    for(i=0;i<n;i++){ 
        for(j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int pre[n][m];
    for(i=0;i<n;i++){ 
        for(j=0;j<m;j++){
            pre[i][j] = arr[i][j];
            if(i-1>=0) pre[i][i] += pre[i-1][j];
            if(j-1>=0) pre[i][j] += pre[i][j-1];
            if(i-1>=0 && j-1>=0) pre[i][j] -= pre[i-1][j-1];
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2,sum=0;
        cin>>x1>>y1>>x2>>y2;
        
    }

    return 0;
}