#include <iostream>
using namespace std;

int main() {
    int num;
    cin>>num;
    int temp = num;
    int rem, count=0;
    while (temp>0) {
        rem = 0;
        rem = temp % 10;
        cout<<rem<<endl;
        temp = temp / 10;
    }
    //cout<<"\nNo. Of Prime Digits : "<<count;
    return 0;
}