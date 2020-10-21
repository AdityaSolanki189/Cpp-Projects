/*Approach :  Check which is greater (x or y)
		    Every first element of every odd column is its square
	         Every first element of every even row is its square

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	ll test;
	cin>>test;
	while(test-->0){
		ll y,x;
		cin>>y>>x;

		if(x>y){ // column is greater than row
			if(x % 2 == 1){ // column is odd
				cout<< (x*x) - y + 1; 
			}
			else{ // column is even
				x--;
				cout<< (x*x) + y;
			}
		}
		else{ // row > column or row == column
			if(y % 2 == 0){ // row is even
				cout<< (y*y) - x + 1;
			}
			else{ // row is odd
				y--;
				cout<< (y*y) + x;
			} 
		}
		cout<<"\n";
	}
	return 0;
}