#include <iostream>
using namespace std;
#define ll long long
int main() {
    ll  num;
    cin>>num;
    ll temp = num;
    ll rem, count=0;
    while (temp>0) {
        rem = 0;
        rem = temp % 10;
        if(rem == 2 || rem == 3 || rem == 5 || rem == 7){
            count++;
            cout<<rem<<" ";
        }
        temp = temp / 10;
    }
    cout<<"\nNo. Of Prime Digits : "<<count;
    return 0;
}