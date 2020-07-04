#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int str[N];
        for(int i=0;i<N;i++){ 
            cin>>str[i];
        }
        int skips = 0,f=0,s=0;
        for(int i=0;(i+1) < N;i++){
            f = str[i];
            s = str[i+1];
            skips = skips + abs(f-s) -1;
        }
        cout<<skips<<endl;
    }
    return 0;
}