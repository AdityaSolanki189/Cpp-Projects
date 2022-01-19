#include <bits/stdc++.h>
using namespace std;
#define li long long int 

int main(){
    li t;
    cin >> t;
    while(t--){
        li c;
        cin >> c;
        li  i=0,d=1;
        while(i <= c){
            i = pow(2, d);
            d++;
        }
        li A = pow(2, d-2) - 1;
        li sum = i - c;
        li B = A+sum;
        cout << A*B << "\n";
    }
    return 0;
}