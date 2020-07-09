#include <iostream>

using namespace std;

int power(int num){
    int sum=0,rem=0;
    while(num!=0){
        rem = num%10;
        sum += rem;
        num = num/10;
    }
    return sum;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N; //number of rounds
        cin>>N;
        int winA=0,winB=0;
        int A[N],B[N];
        int sum1;
        for(int i=1;i<=N;i++){
            cin>>A[i]>>B[i];
        }
        for(int i=1;i<=N;i++){
            if(power(A[i]) > power(B[i])){
                winA++;
            }
            if(power(A[i]) < power(B[i])){
                winB++;
            }
            if(power(A[i]) == power(B[i])){
                winB++;
                winA++;
            }
        }
        if(winA>winB){
            cout<<0<<" "<<winA<<endl;
        }
        else if(winA < winB){
            cout<<1<<" "<<winB<<endl;
        }
        else{
            cout<<2<<" "<<winA<<endl;
        }
    }
    return 0;
}