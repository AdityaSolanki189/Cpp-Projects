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
        int skips = 0;
        if(N%2 == 0){
            for(int i=0;i<N-2;i++){
                int f=0,s=0;
                f = str[i];
                s = str[i+1];
                skips = skips + (abs(f-s) -1);  
            }
        }
        else{
            for(int i=0;i<N-1;i++){
                int f1=0,s1=0;
                f1 = str[i];
                s1 = str[i+1];
                skips = skips + (abs(f1-s1) -1);  
            }
        }
        cout<<skips<<endl;
    }
    return 0;
}

