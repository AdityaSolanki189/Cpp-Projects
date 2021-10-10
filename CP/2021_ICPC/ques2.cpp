#include <bits/stdc++.h>
using namespace std;
#define ll long long

double det(double M[3][3]) {
   double t1 = (M[1][1] * M[2][2])-(M[1][2] * M[2][1]);
   double t2 = (M[1][0] * M[2][2])-(M[1][2] * M[2][0]);
   double t3 = (M[1][0] * M[2][1])-(M[1][1] * M[2][0]);
   return (M[0][0]*t1) + (-M[0][1]*t2) + (M[0][2]*t3);
}

void solve(){
	double M[3][3];
	
	cout << "Enter Point p1 (x, y):";
	cin >> M[0][0] >> M[0][1];
	M[0][2] = 1;
	cout << "Enter Point p2 (x, y):";
	cin >> M[1][0] >> M[1][1];
	M[1][2] = 1;
	cout << "Enter Point p3 (x, y):";
	cin >> M[2][0] >> M[2][1];
	M[2][2] = 1;
	int determinant = det(M);

}

int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t;
	cin>>t;

	while(t--){
        solve();
	}
	return 0 ; 
}
