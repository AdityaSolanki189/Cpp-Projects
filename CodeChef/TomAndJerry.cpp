#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        unsigned long long int TS,JS,wins=0;
        cin>>TS;
        for(JS=1;JS<=TS;JS++){
            here:                
            if(TS%2==0 && JS%2==0){
                TS = TS/2;
                JS = JS/2;
                if(TS%2==0 && JS%2==0){
                    goto here;
                }
                else{
                    goto cont;
                }
            }
            
            cont:
            if(JS%2==0 && TS%2!=0){ //JS even
                wins++;
                continue;
            }
            else{//JS odd
                continue;
            }
        }
        cout<<wins<<endl;
    }
    return 0;
}