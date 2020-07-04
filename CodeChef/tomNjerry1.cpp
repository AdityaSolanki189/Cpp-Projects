#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned long long ts,num1,num2;
        cin>>ts;
        if(ts%2==1){
            num1 = ts/2;
            cout<<num1<<endl;
        }
        else{
            num2 = log2(ts);
            if(std::floor(num2)== num2){
                num1 =0;
                cout<<num1<<endl;
            }
            else{
                while(!(ts % 2)){
                    ts>>=1;
                }
                num1 = ts/2;
                cout<<num1<<endl;
            }
        }
    }
    return 0;
}