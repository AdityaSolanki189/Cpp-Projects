/*Your task is to count for k=1,2,…,n the number of ways 
  two knights can be placed on a k×k chessboard so that 
  they do not attack each other. 
  
  Approach : Find all the combinations of arranging 2 knights 
             on the n*n board. Then, eliminate all the possible
             combinations of locations where the knights can 
             attack each other. Construct a mathematical equation.
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll calc(ll n){
	return (n*n*(n*n-1)-8-24-(n-4)*16-16-24*(n-4)-8*(n-4)*(n-4))/2;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	ll n;
	cin>>n;

	for(ll i = 1;i <= n;i++){
		cout<<calc(i)<<"\n";
	}
	return 0;
}