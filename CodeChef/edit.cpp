#include <iostream>

using namespace std;

int main(){
    int T,N,A[100];
    int count=0,ctr=0,temp[100];
    cin>>T;
    for(int k=0;k<T;k++){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>A[j];
        }       
        ctr=0;
        for(int i=0;i<N;i++){
            if(A[i]==0){
                count=count+1;
            }
            else{
                for(int j=0;j<N;j++){
                    temp[j]=count;
                }
                count=0;
            }    
        }
        for(int i=0;i<N;i++){
            if(temp[i]<5){
                ctr++;
            }
            temp[i]=0;
        }
        if(ctr==0)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
       
    }
    return 0;
}