/*A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.

Given n, construct a beautiful permutation if such a permutation exists.*/

//Approach: even at front the odd after all ven

#include <iostream>
using namespace std;

int main(){
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

	int num;
	cin>>num;

	if(num == 1){
		cout<<1;
		return 0;
	}
	if(num == 2 || num == 3){
		cout<<"NO SOLUTION";
		return 0;
	}
	

	return 0;
}