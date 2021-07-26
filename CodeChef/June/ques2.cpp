#include <iostream>
using namespace std;

int main(){

    int testcase;
    cin >> testcase;

    while(testcase--){
        int n,a,b;
        cin >>n>>a>>b;

        int ans = (2*(180+n))-a-b;
        cout << ans <<endl;
    }

    return 0;
}