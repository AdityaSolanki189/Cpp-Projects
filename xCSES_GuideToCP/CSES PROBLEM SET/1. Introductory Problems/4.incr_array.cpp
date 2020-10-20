#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    ull prev,steps = 0ull,next,n;
    cin>>n>>prev;
    while(--n > 0){
        cin>>next;
        if(prev > next){
            steps += prev - next;
        }
        else{
            prev =  next;
        }
    }
    cout<<steps<<endl;
    return 0;
}

