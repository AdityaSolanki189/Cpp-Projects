/*A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.

Given n, construct a beautiful permutation if such a permutation exists.*/

//Approach: All Even at front, All Odd after all Even numbers

#include <bits/stdc++.h>
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
	else if(num == 3 || num == 2){
		cout<<"NO SOLUTION";
		return 0;
	}
	else{
		string str="";
		for(int i=1;i<=num;i++){
			if(i%2==0){ //even
				cout<<i<<" "; //print all even numbers first
			}
			else{ //odd
				str += to_string(i)+" "; //store all odd numbers (convert int to string then store)
			}
		}
		cout<<str; //print all the odd numbers after all the even numbers
	}
	return 0;
}