/*Your task is to divide the numbers 1,2,…,n 
  into two sets of equal sum. If division is 
  possible then print "YES", else print "NO".
  
  YSK : Sum of 1,2,3,...,n is (n*(n+1))/2.
  Therefore, the 2 Equal Sets will have
	    sum = (n*(n+1))/4 each.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	ll num,sum,wsum;
	cin>>num;
    vector<int> x;

    if(n*(n+1) %4 != 0){
    	cout<<"NO";
    	return 0;
    }



	return 0;
}