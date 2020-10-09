#include <iostream>
using namespace std;
#define ll long long int
int main(){
	ll n;
	cin>>n;
	cout<<n<<" ";
	while(n>1){
		if(n%2 == 0){
			n = n/2;
			cout<<n<<" ";
		}
		else if(n%2 != 0){
			n = (n*3) + 1;
			cout<<n<<" ";
		}
	}
	return 0;
}